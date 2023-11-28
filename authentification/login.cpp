#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &login::loginProcess);
}

login::~login()
{
    delete ui;
}

void login::loginProcess(){

}
