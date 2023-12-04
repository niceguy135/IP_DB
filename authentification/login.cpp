#include "login.h"
#include "ui_login.h"

#include <QSqlQuery>
#include <QString>
#include <QDebug>

login::login(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    curUser = user;

    //########DEBUG
    ui->usernameEdit->setText("Sergey");
    ui->surnameEdit->setText("Ezhov");
}

login::~login()
{
    delete ui;
}

void login::loginProcess(){
    QSqlQuery sqlQuery;
    QString query = "SELECT user_id, name, surname, balance, role FROM users WHERE name = '" +
            ui->usernameEdit->text() + "' AND surname = '" + ui->surnameEdit->text() + "'";

    sqlQuery.exec(query);

    //sqlQuery.exec();

    if (sqlQuery.size() == 0) {
        ui->statusLabel->clear();
        ui->statusLabel->setText("Не получилось зарегаться!");
     } else {
        sqlQuery.next();
        curUser->user_id = sqlQuery.value(0).toString();
        curUser->name = sqlQuery.value(1).toString();
        curUser->surname = sqlQuery.value(2).toString();
        curUser->setBalance(sqlQuery.value(3).toInt());

        if(sqlQuery.value(4).toString().contains("Администратор", Qt::CaseInsensitive)){
            curUser->isAdmin = true;
            emit switchToAdmin();
        } else {
            curUser->isAdmin = false;
            emit switchToRoot();
        }
     }
}
