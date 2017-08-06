#ifndef NOTICEWIDGET_H
#define NOTICEWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class NoticeWidget;
}

class NoticeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeWidget(QWidget *parent = 0);
    ~NoticeWidget();

protected:
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void showEvent(QShowEvent *e);
    void hideEvent(QHideEvent *e);
private:
    int itemHeight();
    int itemCountOnePage();
    Ui::NoticeWidget *ui;
    QTimer m_timer;
};

#endif // NOTICEWIDGET_H
