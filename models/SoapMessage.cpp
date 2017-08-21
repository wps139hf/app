#include "SoapMessage.h"

SoapMessage::SoapMessage(QObject *parent)
    : QObject(parent)
{
    m_http = new QtSoapHttpTransport(this);
    connect(m_http, SIGNAL(responseReady(QtSoapMessage)), this, SLOT(onResponseReady(QtSoapMessage)));
}

void SoapMessage::setRequestMethod(const QString &method)
{
    qDebug() << "method:" << method;
    m_request.clear();
    m_request.setMethod(method, XML_NS);
    m_http->setAction(XML_NS + method);
}

void SoapMessage::addRequestArg(const QString &name, const QString &value)
{
    m_request.addMethodArgument(name, "", value);
}

void SoapMessage::sendRequest(const QString &path)
{
    qDebug() << "path:" << path;
    m_http->setHost(HOST, false, PORT);
    m_http->submitRequest(m_request, path);
    qDebug() << "m_request:" << m_request.toXmlString();
    m_eventLoop.exec();
}

QString SoapMessage::getValueByTag(const QString &tag)
{
    QString strResult("");
    QDomDocument doc;
    doc.setContent(m_response.toXmlString());

    QDomNodeList nodeList = doc.elementsByTagName(tag);
    if (!nodeList.isEmpty()){
        strResult = nodeList.at(0).toElement().text();
    }
    return strResult;
}

void SoapMessage::onResponseReady(const QtSoapMessage &response)
{
    m_response = response;
    qDebug() << "SoapMessage::onResponseReady:" << m_response.toXmlString();
    m_eventLoop.quit();
}
