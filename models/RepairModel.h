#ifndef REPAIRMODEL_H
#define REPAIRMODEL_H

#include "AbstractModel.h"

class RepairModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit RepairModel(QObject *parent = nullptr);

protected:
    void init();
    void handleRequest();
};

#endif // REPAIRMODEL_H
