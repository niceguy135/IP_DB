#ifndef DRINKTYPEWIDGET_H
#define DRINKTYPEWIDGET_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class drinkTypeWidget;
}

class drinkTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drinkTypeWidget(QWidget *parent = nullptr, QStackedWidget* stackPtr = nullptr);
    ~drinkTypeWidget();

private:
    Ui::drinkTypeWidget *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void switchToRoot();
    void getDrinksByType(int index);
};

#endif // DRINKTYPEWIDGET_H
