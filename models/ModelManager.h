#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>
#include "ApplicationModel.h"
#include "AssetModel.h"
#include "MutiRoomModel.h"

class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);
    ApplicationModel *application();
    AssetModel *asset();
    MutiRoomModel *multiRoom();

    static ModelManager *instance();
signals:
    void requestLaunch();
    void requestFinish();
private:
    static ModelManager *m_instance;
};

#endif // MODELMANAGER_H
