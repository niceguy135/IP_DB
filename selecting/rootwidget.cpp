#include "rootwidget.h"
#include "ui_rootwidget.h"

rootWidget::rootWidget(QWidget *parent, QStackedWidget* stackPtr) :
    QWidget(parent),
    ui(new Ui::rootWidget)
{
    ui->setupUi(this);
    curStackedWidget = stackPtr;

    connect(ui->createButton, &QPushButton::clicked, this, &rootWidget::createOrder);
    connect(ui->ordersButton, &QPushButton::clicked, this, &rootWidget::switchToOrdersList);
    connect(ui->exitButton, &QPushButton::clicked, this, &rootWidget::exit);
}

rootWidget::~rootWidget()
{
    delete ui;
}

void rootWidget::switchToOrdersList(){

}

void rootWidget::createOrder(){

}

void rootWidget::exit(){

}
