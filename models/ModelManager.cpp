#include "ModelManager.h"

ModelManager::ModelManager(QObject *parent) : QObject(parent)
{

}

ApplicationModel *ModelManager::application()
{
    static ApplicationModel app(this);
    return &app;
}

CarModel *ModelManager::car()
{
    static CarModel c(this);
    return &c;
}

AssetModel *ModelManager::asset()
{
    static AssetModel a(this);
    return &a;
}

MutiRoomModel *ModelManager::multiRoom()
{
    static MutiRoomModel room(this);
    return &room;
}

PrintModel *ModelManager::print()
{
    static PrintModel p(this);
    return &p;
}

BuyModel *ModelManager::buy()
{
    static BuyModel b(this);
    return &b;
}

RepairModel *ModelManager::repair()
{
    static RepairModel r(this);
    return &r;
}

MessageModel *ModelManager::message()
{
    static MessageModel m(this);
    return &m;
}

ModelManager *ModelManager::m_instance = Q_NULLPTR;
ModelManager *ModelManager::instance()
{
    if(m_instance == Q_NULLPTR){
        m_instance = new ModelManager();
    }
    return m_instance;
}
