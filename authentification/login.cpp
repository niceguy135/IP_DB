#include "login.h"
#include "ui_login.h"

#include "base/user.h"

#include <QSqlQuery>

login::login(QWidget *parent, QStackedWidget* stackPtr) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    curStackedWidget = stackPtr;

    connect(ui->loginButton, &QPushButton::clicked, this, &login::loginProcess);
}

login::~login()
{
    delete ui;
}

void login::loginProcess(){
    QSqlQuery sqlQuery;

    sqlQuery.prepare("SELECT user_id, name, surname, balance FROM users "
                        "WHERE name = :login AND surname = :surname");

    sqlQuery.bindValue(":login", ui->nameLabel->text());
    sqlQuery.bindValue(":surname", ui->surnameLabel->text());

    sqlQuery.exec();

    if (sqlQuery.size() == 0) {
        ui->statusLabel->clear();
        ui->statusLabel->setText("Не получилось зарегаться!");
     } else {
//        fillDiaryMarks(std::move(search_query));
        sqlQuery.next();
        User::getUser(sqlQuery.value(0).toString(),
                      sqlQuery.value(1).toString(),
                      sqlQuery.value(2).toString(),
                      sqlQuery.value(3).toInt());

        mainWidget->switchWidget(DrinkWidgets::Root);
     }
}
