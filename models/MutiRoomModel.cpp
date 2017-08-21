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
    m_soap->setRequestMethod("GetMoltiRoomQuantity");
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetMoltiRoomQuantityResult"));
    qDebug() << "GetMoltiRoomQuantityResult:" << quantity.value("Quantity").toInt();
}

void MutiRoomModel::handleResponse()
{
    qDebug() << "GetMoltiRoomQuantityResult:" << getValueByTag("GetMoltiRoomQuantityResult");
//    m_room.fromJsonString(getValueByTag("GetMoltiRoomListResult"));
    m_errorMsg = getValueByTag("msg");
}
