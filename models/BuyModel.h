#ifndef BUYMODEL_H
#define BUYMODEL_H

#include "AbstractModel.h"

class BuyModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit BuyModel(QObject *parent = nullptr);

protected:
    void init();
    void handleRequest();
};

#endif // BUYMODEL_H
