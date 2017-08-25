#ifndef REPAIRLIST_H
#define REPAIRLIST_H

#include "AnimatedPage.h"
#include "ModelManager.h"

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
    void resizeEvent(QResizeEvent *e);
private:
    bool contains(int key);
    void addItems(const JsonObjectMap &map);
    Ui::RepairList *ui;
    QList<int>m_keyList;
};

#endif // REPAIRLIST_H
