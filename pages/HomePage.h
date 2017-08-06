#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "BasePage.h"

namespace Ui {
class HomePage;
}

class HomePage : public BasePage
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();
public slots:
    void onAppSelected(int index);
protected:
    void init();
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
