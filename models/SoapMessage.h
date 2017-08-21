#ifndef SOAPMESSAGE_H
#define SOAPMESSAGE_H

#include <QObject>
#include <QEventLoop>
#include "qtsoap.h"

#define HOST    "180.153.158.111"
#define PORT    88

#define XML_NS  "http://localhost/"
#define DEFAULT_POST_PATH   "/assets.asmx"

class SoapMessage : public QObject
{
    Q_OBJECT
public:
    explicit SoapMessage(QObject *parent = nullptr);

    void setRequestMethod(const QString &method);
    void addRequestArg(const QString&name, const QString &value);
    void submit(const QString &path = DEFAULT_POST_PATH);

    QString getValueByTag(const QString &tag);
    QString errorString();

public slots:
    void onResponseReady(const QtSoapMessage &response);
protected:
    QtSoapHttpTransport *m_http = Q_NULLPTR;
    QtSoapMessage m_request;
    QtSoapMessage m_response;

    QEventLoop m_eventLoop;
};

#endif // SOAPMESSAGE_H
