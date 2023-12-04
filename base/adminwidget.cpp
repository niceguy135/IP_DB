#include "adminwidget.h"
#include "ui_adminwidget.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

adminWidget::adminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWidget)
{
    ui->setupUi(this);
}

adminWidget::~adminWidget()
{
    delete ui;
}

void adminWidget::executeQuery() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QString adminQuery = ui->lineEdit->text();
    qDebug() << adminQuery;
    QSqlQuery query;

    if(query.prepare(adminQuery)){
        if(query.exec()){
            auto columnsSize = query.record().count();

            ui->tableWidget->setColumnCount(columnsSize);

            // Заполняю таблицу
            int rowCounter = 0;
            while(query.next()){
                ui->tableWidget->insertRow(rowCounter);
                for(int columnInd = 0; columnInd < columnsSize; columnInd++) {
                    ui->tableWidget->setItem(rowCounter, columnInd, new QTableWidgetItem(query.value(columnInd).toString()));
                }
                rowCounter++;

            }
        } else
            qDebug() << "Exec bad!";

            ui->tableWidget->setColumnCount(0);
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Запрос не может быть выполнен!"));
    } else
        qDebug() << "Prepare bad!";
        ui->tableWidget->setColumnCount(0);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Запрос невозможно составить!"));
}
