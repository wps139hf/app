#ifndef MUTIROOMMODEL_H
#define MUTIROOMMODEL_H

#include "AppBaseModel.h"

class MutiRoomModel : public AppBaseModel
{
    Q_OBJECT
public:
    explicit MutiRoomModel(QObject *parent = nullptr);
protected:
    void getQuantity() override;
    void getList() override;
    void filterObjects() override;
};

#endif // MUTIROOMMODEL_H
