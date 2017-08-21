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

QJsonObject MutiRoomModel::object(const QString &timestamp)
{
    for(auto object : m_objectList){
        for(auto key : object.keys()){
            if(key == timestamp){
                return object;
            }
        }
    }

    return QJsonObject();
}

void MutiRoomModel::handleRequest()
{
    m_soap->setRequestMethod("GetMoltiRoomQuantity");
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    QJsonObject quantity = JSON::toObject(m_soap->getValueByTag("GetMoltiRoomQuantityResult"));
    int count = quantity.value("Quantity").toInt();

    qDebug() << "MutiRoomModel, count=" << count;

    m_soap->setRequestMethod("GetMoltiRoomList");
    m_soap->addRequestArg("topQuantity", QString().setNum(count));
    m_soap->addRequestArg("userNo", "sa");
    m_soap->submit();

    m_objectList = JSON::toList(m_soap->getValueByTag("GetMoltiRoomListResult"));
    for(auto object : m_objectList){
        qDebug() << "---------------";
        for(auto key : object.keys()){
            qDebug() << key << ":" << object.value(key);
        }
    }
}

