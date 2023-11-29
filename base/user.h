#ifndef USER_H
#define USER_H

#include "QString"

#include "order.h"

class User
{
public:
    static User* GetCurUser();

    User(QString, QString, QString, int);

    QString user_id;
    QString name;
    QString surname;
    Order* cur_order = nullptr;

    void setBalance(int);
    int getBalance();

private:
    static User* cur_user;
    int balance;
};

#endif // USER_H
