#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
