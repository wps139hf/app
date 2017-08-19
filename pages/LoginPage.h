#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();
signals:
    void logined();

protected:
    void init();

private slots:
    void on_btnLogin_clicked();
    void on_checkBox_clicked(bool checked);
private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
