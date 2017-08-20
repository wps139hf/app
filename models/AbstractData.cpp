#include "AbstractData.h"
#include <QDebug>

AbstractData::AbstractData()
{

}

void AbstractData::debug(const QString &tag)
{
    Q_UNUSED(tag);
}

QJsonObject AbstractData::toJson()
{
    QJsonObject json{
        {"1", 1},
        {"2", 2},
    };
    return json;
}

void AbstractData::fromJson(const QJsonObject &object)
{
    Q_UNUSED(object);
}

QString AbstractData::toJsonString()
{
    QJsonArray array{
        {QJsonValue(toJson())}
    };
#ifdef QT_DEBUG
    return QString(QJsonDocument(array).toJson(QJsonDocument::Indented));
#else
    return QString(QJsonDocument(array).toJson(QJsonDocument::Compact));
#endif
}

bool AbstractData::fromJsonString(const QString &jsonString)
{
    qDebug() << "fromJsonString, " << jsonString;
    QJsonParseError jsonParseError;
    auto doc = QJsonDocument::fromJson(jsonString.toUtf8(), &jsonParseError);
    if(jsonParseError.error == QJsonParseError::NoError){
        if(doc.isArray()){
            qDebug() << "fromJsonString, isArray.";
            QJsonArray array = doc.array();
            if(array.isEmpty()){
                return false;
            }
            QJsonValue value = array.first();
            if(value.isObject()){
                QJsonObject obj = value.toObject();
                fromJson(obj);
            }
            return true;
        }else if(doc.isObject()){
            qDebug() << "fromJsonString, isObject.";
            QJsonObject obj = doc.object();
            fromJson(obj);
            return true;
        }
    }else{
        qDebug() << jsonParseError.errorString();
    }
    return false;
}

