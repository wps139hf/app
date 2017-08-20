#ifndef MESSAGEPAGE_H
#define MESSAGEPAGE_H

#include "BasePage.h"
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QDateTime>
#include <QEvent>
#include <QMouseEvent>
#include <QPushButton>

namespace Ui {
class MessagePage;
}

class MessageBox;
class MessageWidget;

#define       WINDOW_WIDTH                       480
#define       WINDOW_HEIGHT                      800

#define       MESSAGE_BOX_WIDTH                  480
#define       MESSAGE_BOX_HEIGHT                 90
#define       MESSAGE_BOX_ICON_WIDTH             90
#define       MESSAGE_BOX_ICON_HEIGHT            90
#define       MESSAGE_BOX_TEXT_WIDTH             300
#define       MESSAGE_BOX_TEXT_HEIGHT            90
#define       MESSAGE_BOX_TIME_WIDTH             90
#define       MESSAGE_BOX_TIME_HEIGHT            90

#define       MESSAGE_WID_BACK_HEIGHT            40
#define       MESSAGE_WID_BACK_WIDTH             80
#define       MESSAGE_WID_TIME_X                 180
#define       MESSAGE_WID_TIME_Y                 50
#define       MESSAGE_WID_TIME_HEIGHT            15
#define       MESSAGE_WID_TIME_WIDTH             60
#define       MESSAGE_WID_TEXT_X                 40
#define       MESSAGE_WID_TEXT_Y                 80
#define       MESSAGE_WID_TEXT_HEIGHT            300
#define       MESSAGE_WID_TEXT_WIDTH             400



class MessageList : public QWidget
{
    Q_OBJECT

public:
    explicit MessageList(const QStringList &content,QWidget *parent = 0);
    ~MessageList();

signals:
    void messageClicked(QString,QString);

protected:
    void resizeEvent(QResizeEvent *e);

private:
    QListWidget*  m_pList;
    QVector<MessageBox*>message_array;

    int           m_iMessageNum;
};

class MessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBox(const QDateTime &time,QWidget *parent = 0,QString message = "");
    ~MessageBox();

signals:
    void messageBoxClicked(QString , QString);

protected:
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void setLabelMove(bool);

private:
    QLabel *m_pMessageIcon;
    QLabel *m_pMessageText;
    QLabel *m_pMessageTime;

    QString m_sTime;
    QString m_sContent;
    QPoint m_mouseSrcPos;
    QPoint m_mouseDstPos;
    bool mouse_press;
    bool label_move;
    int current_pos_y;
};

class MessagePage : public BasePage
{
    Q_OBJECT

public:
    explicit MessagePage(QWidget *parent = nullptr);
    ~MessagePage();

public slots:
    void setMessageContent(QString, QString);
    void slotBacktoList(bool);

protected:
    void init();
    void resizeEvent(QResizeEvent *e);

private:
    Ui::MessagePage *ui;
    MessageList* m_pMessageList;
    //MessageWidget* m_pMessageWid;

    QLabel *m_pMessageText;
    QLabel *m_pMessageTime;
};

#endif // MESSAGEPAGE_H
