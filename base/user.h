#ifndef USER_H
#define USER_H

#include "QString"

#include "order.h"

class User
{
public:
    static User& getUser(QString uuid, QString name, QString surname, int balance) {
            static User user(uuid, name, surname, balance);
            return user;
        }

    QString user_id;
    QString name;
    QString surname;
    Order* cur_order = nullptr;

    void setBalance(int);
    int getBalance();

private:
    User(QString, QString, QString, int);
    User& operator=( User& );

    int balance;
};

#endif // USER_H
