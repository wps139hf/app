#ifndef CARMODEL_H
#define CARMODEL_H

#include "AppBaseModel.h"

class CarModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit CarModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // CARMODEL_H
