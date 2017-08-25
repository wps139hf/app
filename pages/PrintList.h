#ifndef PRINTLIST_H
#define PRINTLIST_H

#include "AnimatedPage.h"

namespace Ui {
class PrintList;
}

class PrintList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit PrintList(QWidget *parent = 0);
    ~PrintList();
signals:
    void itemSelected();
protected:
    void init();
    void refresh();
private:
    Ui::PrintList *ui;
};

#endif // PRINTLIST_H
