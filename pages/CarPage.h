#ifndef CARPAGE_H
#define CARPAGE_H

#include "BasePage.h"

namespace Ui {
class CarPage;
}

class CarPage : public BasePage
{
    Q_OBJECT

public:
    explicit CarPage(QWidget *parent = 0);
    ~CarPage();
protected:
    void init();
private:
    Ui::CarPage *ui;
};

#endif // CARPAGE_H
