#include "ModelManager.h"

ModelManager::ModelManager(QObject *parent) : QObject(parent)
{

}

ApplicationModel *ModelManager::application()
{
    static ApplicationModel app(this);
    return &app;
}

ModelManager *ModelManager::m_instance = Q_NULLPTR;
ModelManager *ModelManager::instance()
{
    if(m_instance == Q_NULLPTR){
        m_instance = new ModelManager();
    }
    return m_instance;
}
