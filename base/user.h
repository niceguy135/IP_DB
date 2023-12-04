#ifndef USER_H
#define USER_H

#include "QString"
#include <memory>

#include "order.h"

class User
{
public:
    User();
    User(QString, QString, QString, int);

    QString user_id;
    QString name;
    QString surname;
    bool isAdmin = false;

    void setBalance(int);
    int getBalance();

private:
    int balance;
};

#endif // USER_H
