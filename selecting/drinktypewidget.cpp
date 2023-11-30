#include <QtGlobal>

#include "drinktypewidget.h"
#include "ui_drinktypewidget.h"

drinkTypeWidget::drinkTypeWidget(QWidget *parent, User* user) :
    QWidget(parent),
    ui(new Ui::drinkTypeWidget)
{
    ui->setupUi(this);
    curUser = user;

    connect(ui->pushButton, &QPushButton::clicked, this, &drinkTypeWidget::switchToRoot);
    connect(ui->comboBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &drinkTypeWidget::getDrinksByType);
}

drinkTypeWidget::~drinkTypeWidget()
{
    delete ui;
}

void drinkTypeWidget::switchToRoot()
{
    emit switchToRootWidget();
}

void drinkTypeWidget::getDrinksByType(int index)
{

}
