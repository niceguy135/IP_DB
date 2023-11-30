#ifndef ROOTWIDGET_H
#define ROOTWIDGET_H

#include <QWidget>
#include <QStackedWidget>

#include "base/user.h"

namespace Ui {
class rootWidget;
}

class rootWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rootWidget(QWidget *parent = nullptr, User* user = nullptr);
    ~rootWidget();

    User* curUser;

public slots:
    void updateLabel();

private:
    Ui::rootWidget *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void switchToOrdersList();
    void createOrder();
    void exit();
};

#endif // ROOTWIDGET_H
