#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr, QStackedWidget* stackPtr = nullptr);
    ~login();

private:
    Ui::login *ui;
    QStackedWidget *curStackedWidget;

private slots:
    void loginProcess();
};

#endif // LOGIN_H
