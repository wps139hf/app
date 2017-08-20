#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class AbstractData
{
public:
    explicit AbstractData();

    QString toJsonString();
    bool fromJsonString(const QString &jsonString);
    virtual void debug(const QString &tag);

protected:
    virtual QJsonObject toJson();
    virtual void fromJson(const QJsonObject &object);
};

#endif // ABSTRACTDATA_H
