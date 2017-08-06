#ifndef MESSAGEPAGE_H
#define MESSAGEPAGE_H

#include "BasePage.h"

namespace Ui {
class MessagePage;
}

class MessagePage : public BasePage
{
    Q_OBJECT
public:
    explicit MessagePage(QWidget *parent = nullptr);
    ~MessagePage();
protected:
    void init();
private:
    Ui::MessagePage *ui;
};

#endif // MESSAGEPAGE_H
