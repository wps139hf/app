#include "BuyModel.h"
#include "ModelManager.h"

BuyModel::BuyModel(QObject *parent)
    : AbstractModel(parent)
{
}

void BuyModel::init()
{
    m_username = ModelManager::instance()->application()->user();
    m_objectList.clear();
}

void BuyModel::handleRequest()
{
    m_soap->setRequestMethod("GetPurchaseQuantity");
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetPurchaseQuantityResult"));
    int count = quantity.value("Quantity").toInt();

    qDebug() << "BuyModel, count=" << count;

    m_soap->setRequestMethod("GetPurchaseList");
    m_soap->addRequestArg("topQuantity", QString().setNum(count));
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetPurchaseListResult"));
    for(auto object : m_objectList){
//        m_mapBySN.insert(object.value("编号").toString(), object);
        qDebug() << "---------------";
        for(auto key : object.keys()){
            qDebug() << key << ":" << object.value(key);
        }
    }
}
