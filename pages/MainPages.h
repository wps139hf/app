#ifndef PAGEPANEL_H
#define PAGEPANEL_H

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

    void showMsg();
    void showHome();
    void showMine();

private:
    Ui::MainPages *ui;
};

#endif // PAGEPANEL_H
