#ifndef ORDERSWIDGET_H
#define ORDERSWIDGET_H

#include <QWidget>
#include <QStackedWidget>

#include "base/user.h"

namespace Ui {
class orderswidget;
}

class orderswidget : public QWidget
{
    Q_OBJECT

public:
    explicit orderswidget(QWidget *parent = nullptr, User* user = nullptr);
    ~orderswidget();

    User* curUser;

signals:
    void switchToRootWidget();

private:
    Ui::orderswidget *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void switchToRoot();
};

#endif // ORDERSWIDGET_H
