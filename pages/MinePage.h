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
signals:
    void logout();
protected:
    void init();
private slots:
    void on_btnLogout_clicked();
private:
    Ui::MinePage *ui;
};

#endif // MINEPAGE_H
