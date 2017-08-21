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

void MutiRoomModel::request()
{
    m_soap->setRequestMethod("GetMoltiRoomQuantity");
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetMoltiRoomQuantityResult"));
    int count = quantity.value("Quantity").toInt();

    for(int i = 0; i < count; i++){
        m_soap->setRequestMethod("GetMoltiRoomList");
        m_soap->addRequestArg("topQuantity", "1");
        m_soap->addRequestArg("userNo", "sa");
        m_soap->submit();
        m_jsonObjectList.append(JSON::toObject(m_soap->getValueByTag("GetMoltiRoomListResult")));
    }

    m_room.fromJsonString(m_soap->getValueByTag("GetMoltiRoomListResult"));
}

