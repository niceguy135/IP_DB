#include <QtGlobal>
#include <QSqlQuery>
#include <QDebug>

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
    QString query = "SELECT DISTINCT name FROM suppliers";

    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Неудается получить поставщиков!";
     } else {
        ui->supplierCombo->clear();
        ui->supplierCombo->addItem("Не важно");
        while(sqlQuery.next()){
            ui->supplierCombo->addItem(sqlQuery.value(0).toString());
        }
     }
}


void drinkTypeWidget::getStores(){
    QSqlQuery sqlQuery;
    QString query = "SELECT DISTINCT name FROM stores";

    sqlQuery.exec(query);

    if (sqlQuery.size() == 0) {
        qDebug() << "Неудается получить магазины!";
     } else {
        ui->storeCombo->clear();
        ui->storeCombo->addItem("Не важно");
        while(sqlQuery.next()){
            ui->storeCombo->addItem(sqlQuery.value(0).toString());
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
