#ifndef REPAIRPAGE_H
#define REPAIRPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class RepairPage;
}

class RepairPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit RepairPage(QWidget *parent = 0);
    ~RepairPage();

protected:
    void init();
private:
    Ui::RepairPage *ui;
};

#endif // REPAIRPAGE_H
