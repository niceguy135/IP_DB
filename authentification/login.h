#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QStackedWidget>

#include "base/user.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr, User* user = nullptr);
    ~login();

    User* curUser;

signals:
    void switchToRoot();

private:
    Ui::login *ui;

private slots:
    void loginProcess();
};

#endif // LOGIN_H
