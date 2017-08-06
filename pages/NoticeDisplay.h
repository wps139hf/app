#ifndef NOTICEDISPLAY_H
#define NOTICEDISPLAY_H

#include <QWidget>

namespace Ui {
class NoticeDisplay;
}

class NoticeDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeDisplay(QWidget *parent = 0);
    ~NoticeDisplay();

private:
    Ui::NoticeDisplay *ui;
};

#endif // NOTICEDISPLAY_H
