#include "rootwidget.h"
#include "ui_rootwidget.h"

rootWidget::rootWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rootWidget)
{
    ui->setupUi(this);
}

rootWidget::~rootWidget()
{
    delete ui;
}
