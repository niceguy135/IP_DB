#include "rootwidget.h"
#include "ui_rootwidget.h"

#include "base/user.h"

#include <QDebug>

rootWidget::rootWidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::rootWidget)
{
    ui->setupUi(this);
    curUser = user;
}

rootWidget::~rootWidget()
{
    delete ui;
}

void rootWidget::switchToOrdersList(){
    emit switchToOrders();
}

void rootWidget::createOrder(){
    emit switchToDrinks();
}

void rootWidget::exit(){
    emit switchToLogin();
}

void rootWidget::updateLabel(){
    QString newText = "Здраствуйте, " + curUser->name + " " + curUser->surname;
    ui->label->setText(newText);
}
