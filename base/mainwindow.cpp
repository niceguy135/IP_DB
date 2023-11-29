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

    // Setting for interfaces
    _login = new login(nullptr);
    connect(_login, &login::switchToRoot, this, &MainWindow::setRootWidget);

    _drinkTypeWidget = new drinkTypeWidget(nullptr, this->stackedWidget);
    _orderswidget = new orderswidget(nullptr, this->stackedWidget);
    _rootWidget = new rootWidget(nullptr, this->stackedWidget);
}


void MainWindow::setRootWidget(){
    stackedWidget->setCurrentWidget(_rootWidget);
}
