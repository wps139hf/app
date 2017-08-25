#ifndef BUYLIST_H
#define BUYLIST_H

#include "AnimatedPage.h"

namespace Ui {
class BuyList;
}

class BuyList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit BuyList(QWidget *parent = 0);
    ~BuyList();
signals:
    void itemSelected();
protected:
    void init();
    void refresh();
private:
    Ui::BuyList *ui;
};

#endif // BUYLIST_H
