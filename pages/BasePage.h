#ifndef BASEPAGE_H
#define BASEPAGE_H

#include "TitleBar.h"
#include "ToolBar.h"

#include <QDebug>
#include <QWidget>
#include <QKeyEvent>

class BasePage : public QWidget
{
    Q_OBJECT

public:
    explicit BasePage(QWidget *parent = 0);
    ~BasePage();

    void setTitleBar(TitleBar *bar);
    void setToolBar(ToolBar *bar);

    void setTitle(const QString &title);
    void setTitleButtonVisible(TitleBar::Button btn, bool visible);
    void setToolButtonChecked(ToolBar::Button btn);

    void setBackgroundColor(const QColor &color);
    void sendNotification(const QString &notification);
signals:
    void backClicked(bool);
    void customClicked(bool);
    void notified(const QString &notification);
protected:
    virtual void init();
    virtual void refresh();
    void showEvent(QShowEvent *e);
    void keyReleaseEvent(QKeyEvent *event);
protected:
    TitleBar *m_titleBar = Q_NULLPTR;
    ToolBar *m_toolbar = Q_NULLPTR;

    QColor m_backgoundColor = Qt::white;
};

#endif // BASEPAGE_H
