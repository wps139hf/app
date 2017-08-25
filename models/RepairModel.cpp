#include "RepairModel.h"
#include "ModelManager.h"

RepairModel::RepairModel(QObject *parent)
    : AppBaseModel(parent)
{

}

void RepairModel::getQuantity()
{
    m_soap->setRequestMethod("GetRepairQuantity");
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetRepairQuantityResult"));
    m_count = quantity.value("Quantity").toInt();
}

void RepairModel::getList()
{
    m_soap->setRequestMethod("GetRepairList");
    m_soap->addRequestArg("topQuantity", QString().setNum(m_count));
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetRepairQuantityResult"));
}

void RepairModel::filterObjects()
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
