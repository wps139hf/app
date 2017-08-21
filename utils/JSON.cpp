#include "JSON.h"

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

JSON::JSON(QObject *parent) : QObject(parent)
{

}

QJsonObject JSON::toObject(const QString &jsonString)
{
    QJsonObject jsonObject;
    QJsonParseError jsonParseError;
    auto doc = QJsonDocument::fromJson(jsonString.toUtf8(), &jsonParseError);
    if(jsonParseError.error != QJsonParseError::NoError){
        qDebug() << jsonParseError.errorString();
        return jsonObject;
    }

    if(doc.isArray()){
        qDebug() << "JSON::toObject, isArray.";
        QJsonArray array = doc.array();
        if(!array.isEmpty()){
            QJsonValue value = array.first();
            if(value.isObject()){
                jsonObject = value.toObject();
            }
        }
    }else if(doc.isObject()){
        qDebug() << "JSON::toObject, isObject.";
        jsonObject = doc.object();
    }
    return jsonObject;
}
