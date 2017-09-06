#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>
#include "ApplicationModel.h"
#include "AssetModel.h"
#include "MutiRoomModel.h"
#include "PrintModel.h"
#include "BuyModel.h"
#include "CarModel.h"
#include "RepairModel.h"
#include "messagemodel.h"

class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);
    ApplicationModel *application();
    CarModel *car();
    AssetModel *asset();
    MutiRoomModel *multiRoom();
    PrintModel *print();
    BuyModel *buy();
    RepairModel *repair();
    MessageModel *message();

    static ModelManager *instance();
signals:
    void requestLaunch();
    void requestFinish();
private:
    static ModelManager *m_instance;
};

#endif // MODELMANAGER_H
