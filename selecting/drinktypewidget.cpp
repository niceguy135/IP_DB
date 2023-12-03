#include <QtGlobal>
#include <QSqlQuery>
#include <QDebug>
#include <QSet>

#include "drinktypewidget.h"
#include "ui_drinktypewidget.h"

drinkTypeWidget::drinkTypeWidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::drinkTypeWidget)
{
    ui->setupUi(this);
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

    if (sqlQuery.size() == 0) {
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

    if (sqlQuery.size() == 0) {
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

    if (sqlQuery.size() == 0) {
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


void drinkTypeWidget::setMaps(){
    QSqlQuery sqlQuery;


    QString query = "SELECT * FROM store_suppliers_relation";
    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Неудается заполнить store_suppliers_relation!";
     } else {
        while(sqlQuery.next()){
            if(store_suppliers_relation.contains(sqlQuery.value(0).toInt())){
                store_suppliers_relation[sqlQuery.value(0).toInt()].push_back(
                            sqlQuery.value(1).toInt()
                            );
            } else {
                store_suppliers_relation[sqlQuery.value(0).toInt()] = std::vector<int>();
                store_suppliers_relation[sqlQuery.value(0).toInt()].push_back(
                            sqlQuery.value(1).toInt()
                            );
            }

        }
     }

    query = "SELECT * FROM inventory";
    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Неудается заполнить inventory!";
     } else {
        while(sqlQuery.next()){
            if(inventory.contains(sqlQuery.value(0).toInt())){
                inventory[sqlQuery.value(0).toInt()].push_back(
                            sqlQuery.value(1).toInt()
                            );
            } else {
                inventory[sqlQuery.value(0).toInt()] = std::vector<int>();
                inventory[sqlQuery.value(0).toInt()].push_back(
                            sqlQuery.value(1).toInt()
                            );
            }

        }
     }
}


void drinkTypeWidget::switchToRoot()
{
    emit switchToRootWidget();
}

void drinkTypeWidget::applyFilters()
{

}
