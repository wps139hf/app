#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include "BasePage.h"

namespace Ui {
class WelcomePage;
}

class WelcomePage : public BasePage
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = 0);
    ~WelcomePage();
signals:
    void loginClicked();
protected:
    void resizeEvent(QResizeEvent *e);

private:
    Ui::WelcomePage *ui;
};

#endif // WELCOMEPAGE_H
