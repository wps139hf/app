#ifndef PAGEPANEL_H
#define PAGEPANEL_H

#include "TitleBar.h"

#include <QWidget>

namespace Ui {
class MainPages;
}

class MainPages : public QWidget
{
    Q_OBJECT

public:
    explicit MainPages(QWidget *parent = 0);
    ~MainPages();

    void setTitleBar(TitleBar *bar);
    void showMsg();
    void showHome();
    void showMine();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    void showPage(QWidget *page);
    Ui::MainPages *ui;
};

#endif // PAGEPANEL_H
