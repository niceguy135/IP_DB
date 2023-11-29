#include "login.h"
#include "ui_login.h"

#include "base/user.h"

#include <QSqlQuery>
#include <QDebug>

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
    QSqlQuery sqlQuery;
    QString query = "SELECT user_id, name, surname, balance FROM users WHERE name = '" +
            ui->usernameEdit->text() + "' AND surname = '" + ui->surnameEdit->text() + "'";

    sqlQuery.exec(query);

    //sqlQuery.exec();

    if (sqlQuery.size() == 0) {
        ui->statusLabel->clear();
        ui->statusLabel->setText("Не получилось зарегаться!");
        qDebug() << "Bad!";
     } else {
        qDebug() << "Success!";
        sqlQuery.next();
        User(sqlQuery.value(0).toString(),
                      sqlQuery.value(1).toString(),
                      sqlQuery.value(2).toString(),
                      sqlQuery.value(3).toInt());

        emit switchToRoot();
     }
}
