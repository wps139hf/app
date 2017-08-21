#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class RoomPage2;
}

class RoomPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RoomPage(QWidget *parent = 0);
    ~RoomPage();

protected:
    void init();
    void refresh();
private:
    Ui::RoomPage2 *ui2;
};

#endif // ROOMPAGE_H
