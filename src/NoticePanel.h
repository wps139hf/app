#ifndef NOTICEPANEL_H
#define NOTICEPANEL_H

#include <QWidget>

namespace Ui {
class NoticePanel;
}

class NoticePanel : public QWidget
{
    Q_OBJECT

public:
    explicit NoticePanel(QWidget *parent = 0);
    ~NoticePanel();

private:
    Ui::NoticePanel *ui;
};

#endif // NOTICEPANEL_H
