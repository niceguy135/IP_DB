#include "orderswidget.h"
#include "ui_orderswidget.h"

orderswidget::orderswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderswidget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &orderswidget::switchToRoot);
}

orderswidget::~orderswidget()
{
    delete ui;
}

void orderswidget::switchToRoot(){

}
