#ifndef PAGEPANEL_H
#define PAGEPANEL_H

#include <QWidget>

namespace Ui {
class PagePanel;
}

class PagePanel : public QWidget
{
    Q_OBJECT

public:
    explicit PagePanel(QWidget *parent = 0);
    ~PagePanel();

    void showMsg();
    void showHome();
    void showMine();

private:
    Ui::PagePanel *ui;
};

#endif // PAGEPANEL_H
