#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasePage.h"

#include "AbstractPageManager.h"
#include "Notification.h"

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
    void connectionsOnNotification();
    void connectionsOnBusyPage();
    Ui::MainWindow *ui;
    QSharedPointer<Notification> m_notification;
};

#endif // MAINWINDOW_H
