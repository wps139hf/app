#ifndef PAGESTACK_H
#define PAGESTACK_H

#include <QWidget>

namespace Ui {
class PageStack;
}

class PageStack : public QWidget
{
    Q_OBJECT

public:
    explicit PageStack(QWidget *parent = 0);
    ~PageStack();

protected:
    void resizeEvent(QResizeEvent *e);
private:
    Ui::PageStack *ui;
};

#endif // PAGESTACK_H
