#ifndef BASEPAGE_H
#define BASEPAGE_H

#include "TitleBar.h"
#include "ToolBar.h"

#include <QDebug>
#include <QWidget>

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
    void sendError(const QString &err);
signals:
    void backClicked(bool);
    void customClicked(bool);
    void error(const QString &err);
protected:
    virtual void init();
    virtual void updatePage();
    void showEvent(QShowEvent *e);
    void paintEvent(QPaintEvent *e);
protected:
    TitleBar *m_titleBar = Q_NULLPTR;
    ToolBar *m_toolbar = Q_NULLPTR;

    QColor m_backgoundColor = Qt::white;
};

#endif // BASEPAGE_H
