#include "BuyModel.h"
#include "ModelManager.h"

BuyModel::BuyModel(QObject *parent)
    : AppBaseModel(parent)
{
}

void BuyModel::getQuantity()
{
    m_soap->setRequestMethod("GetPurchaseQuantity");
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetPurchaseQuantityResult"));
    m_count = quantity.value("Quantity").toInt();
}

void BuyModel::getList()
{
    m_soap->setRequestMethod("GetPurchaseList");
    m_soap->addRequestArg("topQuantity", QString().setNum(m_count));
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetPurchaseListResult"));
}

void BuyModel::filterObjects()
{
    int index = 0;
    for(auto object : m_objectList){
        QString state = object.value("审批状态").toString();
        if(state == QString("已审批")){
            m_doneMap.insert(index, object);
        }else{
            m_pendingMap.insert(index, object);
        }
        index++;
    }
}
