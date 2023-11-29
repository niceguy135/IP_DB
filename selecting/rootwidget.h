#ifndef ROOTWIDGET_H
#define ROOTWIDGET_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class rootWidget;
}

class rootWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rootWidget(QWidget *parent = nullptr, QStackedWidget* stackPtr = nullptr);
    ~rootWidget();

private:
    Ui::rootWidget *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void switchToOrdersList();
    void createOrder();
    void exit();
};

#endif // ROOTWIDGET_H
