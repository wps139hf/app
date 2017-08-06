#ifndef MINEPAGE_H
#define MINEPAGE_H

#include "BasePage.h"

namespace Ui {
class MinePage;
}

class MinePage : public BasePage
{
    Q_OBJECT

public:
    explicit MinePage(QWidget *parent = 0);
    ~MinePage();
protected:
    void init();
private:
    Ui::MinePage *ui;
};

#endif // MINEPAGE_H
