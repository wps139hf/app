#ifndef REPAIRMODEL_H
#define REPAIRMODEL_H

#include "AppBaseModel.h"

class RepairModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit RepairModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // REPAIRMODEL_H
