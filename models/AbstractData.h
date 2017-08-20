#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <QObject>
#include <QJsonDocument>

class AbstractData : public QObject
{
    Q_OBJECT
public:
    explicit AbstractData(QObject *parent = nullptr);

//    QString toJsonString();
//    bool fromJsonString(const QString &jsonString);

//    virtual void debug(const QString &tag) = 0;

protected:
//    virtual QJsonObject toJson(){
//        QJsonObject obj{
//            {"1", 1},
//        };
//        return obj;
//    }
//    virtual void fromJson(const QJsonObject &object){
//        Q_UNUSED(object);
//    }
};

#endif // ABSTRACTDATA_H
