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

QJsonObject MutiRoomModel::object(const QString &sn)
{
    return m_mapBySN.value(sn);
}

int MutiRoomModel::size()
{
    return m_mapBySN.size();
}

void MutiRoomModel::init()
{
    m_objectList.clear();
    m_mapBySN.clear();
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
        m_mapBySN.insert(object.value("编号").toString(), object);
        qDebug() << "---------------";
        for(auto key : object.keys()){
            qDebug() << key << ":" << object.value(key);
        }
    }
}

