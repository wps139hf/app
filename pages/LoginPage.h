#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "BasePage.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public BasePage
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
