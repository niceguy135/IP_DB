#ifndef USER_H
#define USER_H

#include "QString"
#include <memory>

#include "order.h"

class User
{
public:
    User(QString, QString, QString, int);

    inline static User* curUser;

    QString user_id;
    QString name;
    QString surname;
    Order* cur_order = nullptr;

    void setBalance(int);
    int getBalance();

private:
    int balance;
};

#endif // USER_H
