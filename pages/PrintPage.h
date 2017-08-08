#ifndef PRINTPAGE_H
#define PRINTPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class PrintPage;
}

class PrintPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit PrintPage(QWidget *parent = 0);
    ~PrintPage();

protected:
    void init();
private:
    Ui::PrintPage *ui;
};

#endif // PRINTPAGE_H
