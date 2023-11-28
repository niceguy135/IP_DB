#ifndef ORDER_H
#define ORDER_H

#include "QString"

class Order
{
public:
    Order(QString, QString, int);

    QString order_id;
    QString name;
    int price;
};

#endif // ORDER_H
