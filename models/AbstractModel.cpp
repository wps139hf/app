#include "AbstractModel.h"
#include "ModelManager.h"
#include "config.h"

AbstractModel::AbstractModel(QObject *parent) : QObject(parent)
{
    ModelManager *manager = qobject_cast<ModelManager*>(parent);
    if(manager){
        connect(this, SIGNAL(requestLaunch()), manager, SIGNAL(requestLaunch()));
        connect(this, SIGNAL(requestFinish()), manager, SIGNAL(requestFinish()));
    }

    m_http = new QtSoapHttpTransport(this);
    connect(m_http, SIGNAL(responseReady(QtSoapMessage)), this, SLOT(onResponseReady(QtSoapMessage)));
}

void AbstractModel::commit()
{
    emit requestLaunch();

    handleRequest();
}

QString AbstractModel::errorMsg()
{
    return m_errorMsg;
}

QString AbstractModel::getValueByTag(const QString &tag)
{
    QString strResult;
    QDomDocument doc;
    doc.setContent(m_response.toXmlString());

    QDomNodeList nodeList = doc.elementsByTagName(tag);
    if (!nodeList.isEmpty()){
        strResult = nodeList.at(0).toElement().text();
    }
    return strResult;
}

void AbstractModel::setRequestMethod(const QString &method)
{
    qDebug() << "method:" << method;
    m_request.clear();
    m_request.setMethod(method, XML_NS);
    m_http->setAction(XML_NS + method);
}

void AbstractModel::addRequestArg(const QString &name, const QString &value)
{
    m_request.addMethodArgument(name, "", value);
}

void AbstractModel::sendRequest(const QString &path)
{
    qDebug() << "path:" << path;
    m_http->setHost(HOST, false, PORT);
    m_http->submitRequest(m_request, path);
    qDebug() << "m_request:" << m_request.toXmlString();
}

void AbstractModel::onResponseReady(const QtSoapMessage &response)
{
    m_response = response;
    qDebug() << "m_response:" << m_response.toXmlString();
    handleResponse();

    emit requestFinish();
}

void AbstractModel::handleRequest()
{

}

void AbstractModel::handleResponse()
{

}
