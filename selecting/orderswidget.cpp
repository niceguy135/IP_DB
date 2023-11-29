#include "orderswidget.h"
#include "ui_orderswidget.h"

orderswidget::orderswidget(QWidget *parent, QStackedWidget* stackPtr) :
    QWidget(parent),
    ui(new Ui::orderswidget)
{
    ui->setupUi(this);
    curStackedWidget = stackPtr;

    connect(ui->pushButton, &QPushButton::clicked, this, &orderswidget::switchToRoot);
}

orderswidget::~orderswidget()
{
    delete ui;
}

void orderswidget::switchToRoot(){

}
