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
    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void switchToRoot();

private:
    Ui::login *ui;

private slots:
    void loginProcess();
};

#endif // LOGIN_H
