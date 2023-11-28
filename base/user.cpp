#include "user.h"

User::User(QString uuid, QString name, QString surname, int balance)
    : user_id(uuid), name(name), surname(surname)
{
    this->setBalance(balance);
}


void User::setBalance(int balance){
    if(balance < 0) {
        this->balance = 0;
    } else
        this->balance = balance;
}


int User::getBalance(){
    return this->balance;
}
