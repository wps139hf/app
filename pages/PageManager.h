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

    MessagePage *messagePage();
    HomePage *homePage();
    MinePage *minePage();
    void sendNotification(const QString &notification);
signals:
    void notified(const QString &notification);
protected:
    void resizeEvent(QResizeEvent *e);

private:
    void initPageList();
    void initToolBar();
    void hidePages();
    void showPage(QWidget *page);
    void initConnections();
    Ui::PageManager *ui;
    QList<QWidget *>m_pageList;
};

#endif // PAGEPANEL_H
