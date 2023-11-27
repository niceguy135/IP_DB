#ifndef DRINKTYPEWIDGET_H
#define DRINKTYPEWIDGET_H

#include <QWidget>

namespace Ui {
class drinkTypeWidget;
}

class drinkTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drinkTypeWidget(QWidget *parent = nullptr);
    ~drinkTypeWidget();

private:
    Ui::drinkTypeWidget *ui;

private slots:
    void switchToRoot();
    void getDrinksByType(int drinkTypeInd);
};

#endif // DRINKTYPEWIDGET_H
