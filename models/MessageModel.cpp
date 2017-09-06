#include "MessageModel.h"
#include "ModelManager.h"
MessageModel::MessageModel(QObject *parent)
    : AppBaseModel(parent)
{

}

void MessageModel::getQuantity()
{
    m_soap->setRequestMethod("GetDocumentQuantity");
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetDocumentQuantityResult"));
    m_count = quantity.value("Quantity").toInt();
}

void MessageModel::getList()
{
    m_soap->setRequestMethod("GetDocumentList");
    m_soap->addRequestArg("topQuantity", QString().setNum(m_count));
    m_soap->addRequestArg("userNo", m_username);
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetDocumentListResult"));
}

void MessageModel::filterObjects()
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
