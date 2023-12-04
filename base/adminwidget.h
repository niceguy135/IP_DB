#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>

namespace Ui {
class adminWidget;
}

class adminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit adminWidget(QWidget *parent = nullptr);
    ~adminWidget();

private:
    Ui::adminWidget *ui;

private slots:
    void executeQuery();
};

#endif // ADMINWIDGET_H
