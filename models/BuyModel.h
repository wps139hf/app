#ifndef BUYMODEL_H
#define BUYMODEL_H

#include "AppBaseModel.h"

class BuyModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit BuyModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // BUYMODEL_H
