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
private:
    void initPageList();
    void initConnections();

    void hidePages();
    void showPage(QWidget *page);
    Ui::MainWindow *ui;
    QList<QWidget *>m_pageList;

    bool m_isLogin = false;
};

#endif // MAINWINDOW_H
