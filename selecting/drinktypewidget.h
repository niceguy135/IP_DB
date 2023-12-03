#ifndef DRINKTYPEWIDGET_H
#define DRINKTYPEWIDGET_H

#include <map>
#include <vector>

#include <QWidget>
#include <QStackedWidget>

#include "base/user.h"

namespace Ui {
class drinkTypeWidget;
}

class drinkTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drinkTypeWidget(QWidget *parent = nullptr, User* user = nullptr);
    ~drinkTypeWidget();

    User* curUser;

signals:
    void switchToRootWidget();

private:
    Ui::drinkTypeWidget *ui;
    QStackedWidget *curStackedWidget;

    std::map<int, QString> stores;
    std::map<int, QString> suppliers;

    void getDrinkTypes();
    void getStores();
    void getSuppliers();


private slots:
    void switchToRoot();
    void applyFilters();
};

#endif // DRINKTYPEWIDGET_H
