#include "orderswidget.h"
#include "ui_orderswidget.h"

orderswidget::orderswidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::orderswidget)
{
    ui->setupUi(this);
    curUser = user;
}

orderswidget::~orderswidget()
{
    delete ui;
}

void orderswidget::switchToRoot(){
    emit switchToRootWidget();
}
