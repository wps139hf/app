#ifndef REPAIRLIST_H
#define REPAIRLIST_H

#include "AnimatedPage.h"

namespace Ui {
class RepairList;
}

class RepairList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RepairList(QWidget *parent = 0);
    ~RepairList();
signals:
    void itemSelected();
protected:
    void init();
    void refresh();
private:
    Ui::RepairList *ui;
};

#endif // REPAIRLIST_H
