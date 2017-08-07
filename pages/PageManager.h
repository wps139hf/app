#ifndef PAGEPANEL_H
#define PAGEPANEL_H

#include "TitleBar.h"
#include "ToolBar.h"
#include "MessagePage.h"
#include "HomePage.h"
#include "MinePage.h"

#include <QWidget>

namespace Ui {
class PageManager;
}

class PageManager : public QWidget
{
    Q_OBJECT

public:
    explicit PageManager(QWidget *parent = 0);
    ~PageManager();

    void setTitleBar(TitleBar *bar);
    void setToolBar(ToolBar *bar);
    void showMsg();
    void showHome();
    void showMine();

    MessagePage *messagePage();
    HomePage *homePage();
    MinePage *minePage();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    void showPage(QWidget *page);
    void initConnections();
    Ui::PageManager *ui;
};

#endif // PAGEPANEL_H
