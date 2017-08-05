#ifndef NOTICEWIDGET_H
#define NOTICEWIDGET_H

#include <QWidget>

namespace Ui {
class NoticeWidget;
}

class NoticeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeWidget(QWidget *parent = 0);
    ~NoticeWidget();

private:
    Ui::NoticeWidget *ui;
};

#endif // NOTICEWIDGET_H
