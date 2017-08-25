#ifndef PRINTMODEL_H
#define PRINTMODEL_H

#include "AppBaseModel.h"

class PrintModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit PrintModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // PRINTMODEL_H
