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
    setRequestMethod("GetMoltiRoomList");
    addRequestArg("topQuantity", "1");
    addRequestArg("userNo", "sa");
    sendRequest();
}

void MutiRoomModel::handleResponse()
{
    m_room.fromJsonString(getValueByTag("GetMoltiRoomListResult"));
    m_errorMsg = getValueByTag("msg");
}
