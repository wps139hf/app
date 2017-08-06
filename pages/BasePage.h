#ifndef BASEPAGE_H
#define BASEPAGE_H

#include "TitleBar.h"

#include <QDebug>
#include <QWidget>

class BasePage : public QWidget
{
    Q_OBJECT

public:
    explicit BasePage(QWidget *parent = 0);
    ~BasePage();

    void setTitleBar(TitleBar *bar);
    void setTitle(const QString &title);

    void showBackButton();
    void showCustomButton();
signals:
    void backClicked(bool);
    void customClicked(bool);

protected:
    virtual void init();
    void showEvent(QShowEvent *e);

private:
    TitleBar *m_titleBar = nullptr;
};

#endif // BASEPAGE_H
