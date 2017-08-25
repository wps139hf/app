#ifndef ROOMLIST_H
#define ROOMLIST_H

#include "AnimatedPage.h"
#include "ModelManager.h"


namespace Ui {
class RoomList;
}

class RoomList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RoomList(QWidget *parent = 0);
    ~RoomList();
signals:
    void itemSelected();
protected:
    void init();
    void refresh();
    void resizeEvent(QResizeEvent *e);
private:
    bool contains(int index);
    void addItems(const JsonObjectMap &map);
    Ui::RoomList *ui;
    QList<int>m_keyList;
};

#endif // ROOMLIST_H
