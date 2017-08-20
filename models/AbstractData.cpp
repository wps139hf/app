#include "AbstractData.h"
#include <QDebug>

AbstractData::AbstractData(QObject *parent) : QObject(parent)
{

}
#if 0
QString AbstractData::toJsonString()
{
    QJsonObject jsonObject = toJson();
#ifdef QT_DEBUG
    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Indented));
#else
    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
#endif
}

bool AbstractData::fromJsonString(const QString &jsonString)
{
    QJsonParseError jsonParseError;
    auto doc = QJsonDocument::fromJson(jsonString.toUtf8(), &jsonParseError);
    if(jsonParseError.error == QJsonParseError::NoError){
        if(doc.isObject()){
            QJsonObject obj = doc.object();
            fromJson(obj);
            return true;
        }
    }else{
        qDebug() << jsonParseError.errorString();
    }
    return false;
}
#endif
