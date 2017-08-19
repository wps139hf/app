#ifndef BUSYPAGE_H
#define BUSYPAGE_H

#include <QWidget>

namespace Ui {
class BusyPage;
}

class BusyPage : public QWidget
{
    Q_OBJECT

public:
    explicit BusyPage(QWidget *parent = 0);
    ~BusyPage();

private:
    Ui::BusyPage *ui;
};

#endif // BUSYPAGE_H
