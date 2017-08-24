#include "RepairModel.h"
#include "ModelManager.h"

RepairModel::RepairModel(QObject *parent)
    : AbstractModel(parent)
{

}

void RepairModel::init()
{
    m_username = ModelManager::instance()->application()->user();
    m_objectList.clear();
    m_mapBySN.clear();
}

void RepairModel::handleRequest()
{
    m_soap->setRequestMethod("GetRepairQuantity");
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetRepairQuantityResult"));
    int count = quantity.value("Quantity").toInt();

    m_soap->setRequestMethod("GetRepairList");
    m_soap->addRequestArg("topQuantity", QString().setNum(count));
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetRepairQuantityResult"));
    for(auto object : m_objectList){
        m_mapBySN.insert(object.value("编号").toString(), object);
        qDebug() << "---------------";
        for(auto key : object.keys()){
            qDebug() << key << ":" << object.value(key);
        }
    }
}
