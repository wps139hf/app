#ifndef PRINTLIST_H
#define PRINTLIST_H

#include "AnimatedPage.h"
#include "ModelManager.h"

namespace Ui {
class PrintList;
}

class PrintList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit PrintList(QWidget *parent = 0);
    ~PrintList();
signals:
    void itemSelected();
    void request();
protected:
    void init();
    void refresh();
    void resizeEvent(QResizeEvent *e);
private:
    bool contains(int key);
    void addItems(const JsonObjectMap &map);
    Ui::PrintList *ui;
    QList<int>m_keyList;
};

#endif // PRINTLIST_H
