#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory.h>

#include <QMainWindow>
#include <QStackedWidget>

#include "authentification/login.h"
#include "selecting/drinktypewidget.h"
#include "selecting/orderswidget.h"
#include "selecting/rootwidget.h"

#include "databaseStuff/sqlservice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login* _login;
    drinkTypeWidget* _drinkTypeWidget;
    orderswidget* _orderswidget;
    rootWidget* _rootWidget;

    QStackedWidget *stackedWidget;
    std::shared_ptr<SqlService> database_unit_;
    void initDatabaseInterfaces();

private:
    Ui::MainWindow *ui;

private slots:
    void setRootWidget();
    void setLoginWidget();
    void setDrinkWidget();
    void setOrdersWidget();
};
#endif // MAINWINDOW_H
