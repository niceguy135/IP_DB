#include <QtGlobal>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <set>

#include "drinktypewidget.h"
#include "ui_drinktypewidget.h"

drinkTypeWidget::drinkTypeWidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::drinkTypeWidget)
{
    ui->setupUi(this);

    QStringList headers = (QStringList() << "Наименование" << "Градус" << "Цена");

    ui->tableWidget->setColumnCount(5); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Скрываем колонку под номером 3
    ui->tableWidget->hideColumn(3);
    ui->tableWidget->hideColumn(4);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    curUser = user;

    this->getDrinkTypes();
    this->getStores();
    this->getSuppliers();
}

drinkTypeWidget::~drinkTypeWidget()
{
    delete ui;
}

void drinkTypeWidget::getDrinkTypes(){
    QSqlQuery sqlQuery;
    QString query = "SELECT DISTINCT type FROM products";

    sqlQuery.exec(query);

    if (sqlQuery.size() <= 0) {
        qDebug() << "Неудается получить типы напитков!";
     } else {
        ui->comboBox->clear();
        while(sqlQuery.next()){
            ui->comboBox->addItem(sqlQuery.value(0).toString());
        }
     }
}


void drinkTypeWidget::getSuppliers(){
    QSqlQuery sqlQuery;
    QString query = "SELECT DISTINCT name, supplier_id FROM suppliers";

    sqlQuery.exec(query);

    if (sqlQuery.size() <= 0) {
        qDebug() << "Неудается получить поставщиков!";
     } else {
        ui->supplierCombo->clear();
        ui->supplierCombo->addItem("Не важно");
        while(sqlQuery.next()){
            ui->supplierCombo->addItem(sqlQuery.value(0).toString());

            suppliers[sqlQuery.value(1).toInt()] = sqlQuery.value(0).toString();
        }
     }
}


void drinkTypeWidget::getStores(){
    QSqlQuery sqlQuery;
    QString query = "SELECT DISTINCT address, name, store_id FROM stores";

    sqlQuery.exec(query);

    if (sqlQuery.size() <= 0) {
        qDebug() << "Неудается получить магазины!";
     } else {
        ui->storeCombo->clear();
        ui->storeCombo->addItem("Не важно");
        while(sqlQuery.next()){
            ui->storeCombo->addItem(sqlQuery.value(1).toString());

            stores[sqlQuery.value(2).toInt()] = sqlQuery.value(1).toString();
        }
     }
}


void drinkTypeWidget::switchToRoot()
{
    emit switchToRootWidget();
}

void drinkTypeWidget::applyFilters()
{
    std::set<int> matchedStoresBySuppliers;
    std::set<int> matchedStoresByDrink;

    QSqlQuery sqlQuery;

    //фильтруем магазины по выбранному алкоголю
    QString query = "select distinct store_id from inventory "
            "where product_id IN"
            "("
                "select product_id from products "
                "where type = '" + ui->comboBox->currentText() + "'"
            ")";

    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Ничего нет от store_suppliers_relation!";
    } else {
        while(sqlQuery.next()){
            matchedStoresByDrink.insert(sqlQuery.value(0).toInt());
        }
    }


    //фильтруем магазины по выбранному поставщику
    if(ui->supplierCombo->currentIndex() != 0){
        int supplierID;

        for (auto& it : suppliers) {
            if (it.second == ui->supplierCombo->currentText()) {
                supplierID = it.first;
                break;
            }
        }
        QString query = "SELECT store_id FROM store_suppliers_relation "
                "WHERE supplier_id = " + QString::number(supplierID);

        sqlQuery.exec(query);

        if (sqlQuery.size() == 0) {
            qDebug() << "Ничего нет от store_suppliers_relation!";
         } else {
            while(sqlQuery.next()){
                matchedStoresBySuppliers.insert(sqlQuery.value(0).toInt());
            }
         }
    }


    std::set<int> *filteredStores;
    matchedStoresByDrink.merge(matchedStoresBySuppliers);
    if(matchedStoresBySuppliers.size() == 0)
        filteredStores = &matchedStoresByDrink;
    else
        filteredStores = &matchedStoresBySuppliers;

    if(ui->storeCombo->currentIndex() != 0){
        int storeID;

        for (auto& it : stores) {
            if (it.second == ui->storeCombo->currentText()) {
                storeID = it.first;
                break;
            }
        }
        if (auto search = filteredStores->find(storeID); search == filteredStores->end()) {
            qDebug() << "Отфильтровано, но нужных магазинов не найдено";
            return;
        }

    }

    //получаем напитки
    QString subquery;

    subquery = "select product_id from inventory where store_id IN (";
    if(ui->storeCombo->currentIndex() != 0){
        int storeID = -1;

        for (auto& it : stores) {
            if (it.second == ui->storeCombo->currentText()) {
                storeID = it.first;
                break;
            }
        }
        subquery += QString::number(storeID);
    } else {
        for(auto& elem : *filteredStores){
            subquery += QString::number(elem);
            subquery += " , ";
        }
        subquery += "-2";
    }
    subquery += ")";

    query = "select name, strength, price, store_id, products.product_id from products inner join inventory "
            "on products.product_id = inventory.product_id "
            "where products.product_id IN"
            "(" + subquery + ")"
            "and products.type = '" + ui->comboBox->currentText() + "'";


    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Ничего нет от store_suppliers_relation!";
    } else {
        ui->tableWidget->setRowCount(0);
        auto curRow = 0;
        while(sqlQuery.next()){
            ui->tableWidget->insertRow(curRow);
            ui->tableWidget->setItem(curRow,0, new QTableWidgetItem(sqlQuery.value(0).toString()));
            ui->tableWidget->setItem(curRow,1, new QTableWidgetItem(sqlQuery.value(1).toString()));
            ui->tableWidget->setItem(curRow,2, new QTableWidgetItem(sqlQuery.value(2).toString()));
            ui->tableWidget->setItem(curRow,3, new QTableWidgetItem(sqlQuery.value(3).toString()));
            ui->tableWidget->setItem(curRow,4, new QTableWidgetItem(sqlQuery.value(4).toString()));
            curRow++;
        }
    }

}


void drinkTypeWidget::addDrinkToOrders(){
    QItemSelectionModel *select = ui->tableWidget->selectionModel();

    if(!select->hasSelection())
        return;

    auto selectedDrinkRow  = select->selectedIndexes().at(0).row();

    auto selectedDrinkId = ui->tableWidget->item(selectedDrinkRow, 4)->text();
    auto selectedDrinkPrice = ui->tableWidget->item(selectedDrinkRow, 2)->text();
    auto selectedStoreId = ui->tableWidget->item(selectedDrinkRow, 3)->text();
    auto orderAddress = ui->addressEdit->text();
    auto orderName = ui->orderNameEdit->text();
    if(orderName == "")
        orderName = "Мой заказ";

    QSqlQuery query;
    query.prepare("insert into orders (user_id, store_id, product_id, price, name, address) "
                  "values "
                  "(:user_id, :store_id, :product_id, :price, :name, :address)");

    query.bindValue(":user_id", curUser->user_id.toInt());
    query.bindValue(":store_id", selectedStoreId.toInt());
    query.bindValue(":product_id", selectedDrinkId.toInt());
    query.bindValue(":price", selectedDrinkPrice);
    query.bindValue(":name", orderName);
    query.bindValue(":address", orderAddress);
    query.exec();

}
