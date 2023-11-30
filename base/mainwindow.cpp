#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Stacked widget является скелетом приложения
    stackedWidget = new QStackedWidget();

    initDatabaseInterfaces();

    stackedWidget->addWidget(_login);
    stackedWidget->addWidget(_drinkTypeWidget);
    stackedWidget->addWidget(_orderswidget);
    stackedWidget->addWidget(_rootWidget);

    stackedWidget->setCurrentWidget(_login);

    setCentralWidget(stackedWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initDatabaseInterfaces()
{
    database_unit_ = std::make_unique<SqlService>();
    database_unit_->databaseConnect();

    curUser = new User();

    // Setting for interfaces
    _login = new login(nullptr, curUser);
    _drinkTypeWidget = new drinkTypeWidget(nullptr, curUser);
    _orderswidget = new orderswidget(nullptr, curUser);
    _rootWidget = new rootWidget(nullptr, curUser);

    //сигналы из логина
    connect(_login, &login::switchToRoot, _rootWidget, &rootWidget::updateLabel);
    connect(_login, &login::switchToRoot, this, &MainWindow::setRootWidget);

    //сигналы из рут виджета
    connect(_rootWidget, &rootWidget::switchToLogin, this, &MainWindow::setLoginWidget);
    connect(_rootWidget, &rootWidget::switchToOrders, this, &MainWindow::setOrdersWidget);
    connect(_rootWidget, &rootWidget::switchToDrinks, this, &MainWindow::setDrinkWidget);

    //сигналы из списка заказов
    connect(_orderswidget, &orderswidget::switchToRootWidget, this, &MainWindow::setRootWidget);

    //сигналы из напитков
    connect(_drinkTypeWidget, &drinkTypeWidget::switchToRootWidget, this, &MainWindow::setRootWidget);
}


void MainWindow::setRootWidget(){
    stackedWidget->setCurrentWidget(_rootWidget);
}


void MainWindow::setLoginWidget(){
    stackedWidget->setCurrentWidget(_login);
}


void MainWindow::setDrinkWidget(){
    stackedWidget->setCurrentWidget(_drinkTypeWidget);
}


void MainWindow::setOrdersWidget(){
    stackedWidget->setCurrentWidget(_orderswidget);
}
