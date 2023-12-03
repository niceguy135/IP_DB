#include "orderswidget.h"
#include "ui_orderswidget.h"

#include <QSqlQuery>
#include <QDebug>

orderswidget::orderswidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::orderswidget)
{
    ui->setupUi(this);

    QStringList headers = (QStringList() << "Номер заказа" << "Название заказа" << "Продукт" << "Цена"
                           << "Магазин" << "Адрес" << "Дата" << "Статус");

    ui->tableWidget->setColumnCount(8); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    updateTable();

    curUser = user;
}

orderswidget::~orderswidget()
{
    delete ui;
}

void orderswidget::updateTable(){
    QSqlQuery sqlQuery;
    QString query = "SELECT order_id, orders.name, products.name, price, "
                        "stores.name, orders.address, date, state "
                    "FROM orders inner join products on orders.product_id = products.product_id "
                    "inner join stores on orders.store_id = stores.store_id "
                    "order by order_id";

    sqlQuery.exec(query);

    if (sqlQuery.size() <= 0) {
        qDebug() << "Неудается получить типы напитков!";
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
            ui->tableWidget->setItem(curRow,5, new QTableWidgetItem(sqlQuery.value(5).toString()));
            ui->tableWidget->setItem(curRow,6, new QTableWidgetItem(sqlQuery.value(6).toString()));
            ui->tableWidget->setItem(curRow,7, new QTableWidgetItem(sqlQuery.value(7).toString()));
            curRow++;
        }
     }
}


void orderswidget::switchToRoot(){
    emit switchToRootWidget();
}
