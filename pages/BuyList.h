#ifndef BUYLIST_H
#define BUYLIST_H

#include "AnimatedPage.h"
#include "ModelManager.h"

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
    void resizeEvent(QResizeEvent *e);
private:
    bool contains(int key);
    void addItems(const JsonObjectMap &map);
    Ui::BuyList *ui;
    QList<int>m_keyList;
};

#endif // BUYLIST_H
