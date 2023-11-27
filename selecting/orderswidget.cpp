#include "orderswidget.h"
#include "ui_orderswidget.h"

orderswidget::orderswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderswidget)
{
    ui->setupUi(this);
}

orderswidget::~orderswidget()
{
    delete ui;
}
