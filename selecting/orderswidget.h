#ifndef ORDERSWIDGET_H
#define ORDERSWIDGET_H

#include <QWidget>

namespace Ui {
class orderswidget;
}

class orderswidget : public QWidget
{
    Q_OBJECT

public:
    explicit orderswidget(QWidget *parent = nullptr);
    ~orderswidget();

private:
    Ui::orderswidget *ui;

private slots:
    void switchToRoot();
};

#endif // ORDERSWIDGET_H
