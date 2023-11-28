#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initDatabaseInterfaces();

    // Stacked widget является скелетом приложения
    stackedWidget = new QStackedWidget();

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

    // Setting for interfaces
    _login = new login();
    _drinkTypeWidget = new drinkTypeWidget();
    _orderswidget = new orderswidget();
    _rootWidget = new rootWidget();
}
