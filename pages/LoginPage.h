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
    void loginClicked();

protected:
    void init();
private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
