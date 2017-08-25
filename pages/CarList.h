#ifndef CARLIST_H
#define CARLIST_H

#include "AnimatedPage.h"

namespace Ui {
class CarList;
}

class CarList : public AnimatedPage
{
    Q_OBJECT

public:
    explicit CarList(QWidget *parent = 0);
    ~CarList();
signals:
    void itemSelected();
protected:
    void init();
    void refresh();
//    void resizeEvent(QResizeEvent *e);
private:
    bool contains(const QString &key);
    Ui::CarList *ui;
};

#endif // CARLIST_H
