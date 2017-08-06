#ifndef NOTICEDISPLAY_H
#define NOTICEDISPLAY_H

#include "BasePage.h"

namespace Ui {
class NoticeDisplay;
}

class NoticeDisplay : public BasePage
{
    Q_OBJECT

public:
    explicit NoticeDisplay(QWidget *parent = 0);
    ~NoticeDisplay();

protected:
    void resizeEvent(QResizeEvent *e);
private:
    Ui::NoticeDisplay *ui;
};

#endif // NOTICEDISPLAY_H
