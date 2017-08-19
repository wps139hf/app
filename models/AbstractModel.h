#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QObject>
#include "qtsoap.h"

#define XML_NS  "http://localhost/"
#define DEFAULT_POST_PATH   "/assets.asmx"


class AbstractModel : public QObject
{
    Q_OBJECT
public:
    explicit AbstractModel(QObject *parent = nullptr);
    void commit();
    QString errorMsg();

    QString getValueByTag(const QString &tag);
    void setRequestMethod(const QString &method);
    void addRequestArg(const QString&name, const QString &value);
    void sendRequest(const QString &path = DEFAULT_POST_PATH);
signals:
    void requestLaunch();
    void requestFinish();
public slots:
    void onResponseReady(const QtSoapMessage &response);
protected:
    virtual void handleRequest();
    virtual void handleResponse();
    QString m_errorMsg;
protected:
    QtSoapHttpTransport *m_http = Q_NULLPTR;
    QtSoapMessage m_request;
    QtSoapMessage m_response;
};

#endif // ABSTRACTMODEL_H
