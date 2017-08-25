#include "MutiRoomModel.h"
#include "ModelManager.h"

MutiRoomModel::MutiRoomModel(QObject *parent)
    : AppBaseModel(parent)
{

}

void MutiRoomModel::getQuantity()
{
    m_soap->setRequestMethod("GetMoltiRoomQuantity");
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetMoltiRoomQuantityResult"));
    m_count = quantity.value("Quantity").toInt();
}

void MutiRoomModel::getList()
{
    m_soap->setRequestMethod("GetMoltiRoomList");
    m_soap->addRequestArg("topQuantity", QString().setNum(m_count));
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetMoltiRoomListResult"));
}

void MutiRoomModel::filterObjects()
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

