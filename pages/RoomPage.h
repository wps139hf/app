#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class RoomPage;
}

class RoomPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RoomPage(QWidget *parent = 0);
    ~RoomPage();

protected:
    void init();
private:
    Ui::RoomPage *ui;
};

#endif // ROOMPAGE_H
