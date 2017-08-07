#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasePage.h"

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *e);
    void keyPressEvent(QKeyEvent *e);
private:
    void initPageList();
    void initToolBar();
    void initConnections();

    void hidePagesNoToolBar();
    void showPage(BasePage *page);
    Ui::MainWindow *ui;
    QList<BasePage *>m_listNoToolBarPage;

    bool m_isLogin = false;
};

#endif // MAINWINDOW_H
