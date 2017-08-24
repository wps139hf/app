#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QObject>
#include "SoapMessage.h"
#include "JSON.h"

typedef QMap<QString, QJsonObject> JsonMap;

class AbstractModel : public QObject
{
    Q_OBJECT
public:
    explicit AbstractModel(QObject *parent = nullptr);
    void request();
    QString errorMsg();
signals:
    void requestLaunch();
    void requestFinish();
protected:
    virtual void init();
    virtual void handleRequest();
    QString m_errorMsg;
protected:
    SoapMessage *m_soap = Q_NULLPTR;
};

#endif // ABSTRACTMODEL_H
