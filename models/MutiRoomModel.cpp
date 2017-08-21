#include "MutiRoomModel.h"

MultiRoom::MultiRoom()
{

}

QJsonObject MultiRoom::toJson()
{
    return data;
}

void MultiRoom::fromJson(const QJsonObject &object)
{
    data = object;
}

MutiRoomModel::MutiRoomModel(QObject *parent)
    : AbstractModel(parent)
{

}

QJsonValue MutiRoomModel::value(const QString &key) const
{
    return m_room.data.value(key);
}

void MutiRoomModel::handleRequest()
{
#if 0
    setRequestMethod("GetMoltiRoomList");
    addRequestArg("topQuantity", "1");
    addRequestArg("userNo", "sa");
    sendRequest();
#endif

    qDebug() << "m_soap->sendRequest()..start";
    m_soap->setRequestMethod("GetMoltiRoomQuantity");
    m_soap->addRequestArg("userNo", "sa");
    m_soap->sendRequest();
    qDebug() << "m_soap->sendRequest()..end";
    qDebug() << "GetMoltiRoomQuantityResult:" << m_soap->getValueByTag("GetMoltiRoomQuantityResult");
}

void MutiRoomModel::handleResponse()
{
    qDebug() << "GetMoltiRoomQuantityResult:" << getValueByTag("GetMoltiRoomQuantityResult");
//    m_room.fromJsonString(getValueByTag("GetMoltiRoomListResult"));
    m_errorMsg = getValueByTag("msg");
}
