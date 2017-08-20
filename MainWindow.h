#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasePage.h"

#include "AbstractPageManager.h"

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

    void showBusyPage(bool enabled);
    QWidget *busyPage();

protected:
    void setupConnections();
private:
    void bindModels();
    Ui::MainWindow *ui;
    void wait(int msecond);
};

#endif // MAINWINDOW_H
