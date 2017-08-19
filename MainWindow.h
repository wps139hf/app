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

protected:
    void setupConnections();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
