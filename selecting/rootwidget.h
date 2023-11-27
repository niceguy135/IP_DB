#ifndef ROOTWIDGET_H
#define ROOTWIDGET_H

#include <QWidget>

namespace Ui {
class rootWidget;
}

class rootWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rootWidget(QWidget *parent = nullptr);
    ~rootWidget();

private:
    Ui::rootWidget *ui;

private slots:
    void switchToOrdersList();
    void exit();
    void createOrder();
};

#endif // ROOTWIDGET_H
