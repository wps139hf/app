#ifndef ROOMLIST_H
#define ROOMLIST_H

#include "AnimatedPage.h"
#include "ListItem.h"

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
private:
    bool contains(const QString &key);
    Ui::RoomList *ui;

    QList<QString>m_keyList;
};

#endif // ROOMLIST_H
