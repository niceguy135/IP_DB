#ifndef DRINKTYPEWIDGET_H
#define DRINKTYPEWIDGET_H

#include <QMap>
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

    QMap<int, QString> stores;
    QMap<int, QString> suppliers;

    QMap<int, std::vector<int>> store_suppliers_relation;
    QMap<int, std::vector<int>> inventory;

    void getDrinkTypes();
    void getStores();
    void getSuppliers();
    void setMaps();


private slots:
    void switchToRoot();
    void applyFilters();
};

#endif // DRINKTYPEWIDGET_H
