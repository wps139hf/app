#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasePage.h"

#include "AbstractPageManager.h"
#include "Notification.h"

#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public AbstractPageManager
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow *instance();

protected:
    void setupConnections();

private:
    void startUp();
    void wait(int msecond);
    void connectionsOnLogin();
    void connectionsOnNotification();
    void connectionsOnBusyPage();
    void connectionsOnCar();
    void connectionsOnRepair();
    void connectionsOnBuy();
    void connectionsOnPrint();
    void connectionsOnRoom();
    void connectionsOnAsset();

private:
    Ui::MainWindow *ui;
    QSharedPointer<Notification> m_notification;
//    QStack<QWidget*> m_pageStack;
};

#endif // MAINWINDOW_H
