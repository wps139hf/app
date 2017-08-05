#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QWidget>

namespace Ui {
class BasePage;
}

class BasePage : public QWidget
{
    Q_OBJECT

public:
    explicit BasePage(QWidget *parent = 0);
    ~BasePage();

    void setTitle(const QString &title);

signals:
    void backClicked(bool);
    void customClicked(bool);
protected:
    void resizeEvent(QResizeEvent *e);
private:
    Ui::BasePage *ui;
};

#endif // BASEPAGE_H
