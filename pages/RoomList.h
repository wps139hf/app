#ifndef ROOMLIST_H
#define ROOMLIST_H

#include "AnimatedPage.h"

namespace Ui {
class RoomList;
}

class RoomList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RoomList(QWidget *parent = 0);
    ~RoomList();
protected:
    void init();
    void refresh();
private:
    Ui::RoomList *ui;
};

#endif // ROOMLIST_H
