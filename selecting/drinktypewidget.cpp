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
        while(sqlQuery.next()){
            ui->comboBox->addItem(sqlQuery.value(0).toString());
        }
     }
}


void drinkTypeWidget::switchToRoot()
{
    emit switchToRootWidget();
}

void drinkTypeWidget::getDrinksByType(QString newDrink)
{

}
