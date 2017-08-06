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
signals:
    void backClicked(bool);
    void customClicked(bool);

protected:
    virtual void init();
    void showEvent(QShowEvent *e);

protected:
    TitleBar *m_titleBar = nullptr;
    ToolBar *m_toolbar = nullptr;
};

#endif // BASEPAGE_H
