#ifndef CARPAGE_H
#define CARPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class CarPage;
}

class CarPage : public AnimatedPage
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
