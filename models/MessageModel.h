#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include "AppBaseModel.h"

class MessageModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit MessageModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // MESSAGEMODEL_H
