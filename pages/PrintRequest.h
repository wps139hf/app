#ifndef PRINTREQUEST_H
#define PRINTREQUEST_H

#include "AnimatedPage.h"

namespace Ui {
class PrintRequest;
}

class PrintRequest : public AnimatedPage
{
    Q_OBJECT

public:
    explicit PrintRequest(QWidget *parent = 0);
    ~PrintRequest();

protected:
    void init();
//    void refresh();
private:
    Ui::PrintRequest *ui;
};

#endif // PRINTREQUEST_H
