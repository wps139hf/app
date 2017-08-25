#include "AppBaseModel.h"
#include "ModelManager.h"
#include <QDebug>

AppBaseModel::AppBaseModel(QObject *parent)
    : AbstractModel(parent)
{

}

void AppBaseModel::setCurrentObject(int index)
{
    if(index < m_pendingMap.size()){
        m_currentObject = m_pendingMap.value(index);
    }else{
        m_currentObject = m_doneMap.value(index);
    }
}

QJsonObject AppBaseModel::currentObject()
{
    return m_currentObject;
}

JsonObjectMap AppBaseModel::pendingMap()
{
    return m_pendingMap;
}

JsonObjectMap AppBaseModel::doneMap()
{
    return m_doneMap;
}

void AppBaseModel::init()
{
    m_username = ModelManager::instance()->application()->user();
    m_count = 0;
    m_objectList.clear();
    m_pendingMap.clear();
    m_doneMap.clear();
}

void AppBaseModel::handleRequest()
{
    getQuantity();
    if(m_count > 0){
        qDebug() << "count = " << m_count;
        getList();
        filterObjects();
        outputObject();
    }
}

void AppBaseModel::outputObject()
{
    for(auto object : m_objectList){
        qDebug() << "---------------:";
        for(auto key : object.keys()){
            qDebug() << key << ":" << object.value(key);
        }
    }
}

void AppBaseModel::getQuantity()
{

}

void AppBaseModel::getList()
{

}

void AppBaseModel::filterObjects()
{

}
