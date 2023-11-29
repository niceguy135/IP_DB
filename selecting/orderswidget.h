#ifndef ORDERSWIDGET_H
#define ORDERSWIDGET_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class orderswidget;
}

class orderswidget : public QWidget
{
    Q_OBJECT

public:
    explicit orderswidget(QWidget *parent = nullptr, QStackedWidget* stackPtr = nullptr);
    ~orderswidget();

private:
    Ui::orderswidget *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void switchToRoot();
};

#endif // ORDERSWIDGET_H
