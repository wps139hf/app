#ifndef BUYPAGE_H
#define BUYPAGE_H

#include "AnimatedPage.h"
namespace Ui {
class BuyPage;
}

class BuyPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit BuyPage(QWidget *parent = 0);
    ~BuyPage();

protected:
    void init();
private:
    Ui::BuyPage *ui;
};

#endif // BUYPAGE_H
