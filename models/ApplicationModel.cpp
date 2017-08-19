#include "ApplicationModel.h"
#include "ModelManager.h"

#include <QtConcurrent>

ApplicationModel::ApplicationModel(QObject *parent) : QObject(parent)
{
    ModelManager *manager = qobject_cast<ModelManager*>(parent);
    if(manager){
        connect(this, SIGNAL(requestLaunch()), manager, SIGNAL(requestLaunch()));
        connect(this, SIGNAL(requestFinish()), manager, SIGNAL(requestFinish()));
    }

    m_http = new QtSoapHttpTransport(this);
    connect(m_http, SIGNAL(responseReady(QtSoapMessage)), this, SLOT(onResponseReady(QtSoapMessage)));
}

void ApplicationModel::setUser(const QString &user)
{
    m_username = user;
}

void ApplicationModel::setPassword(const QString &password)
{
    m_password = password;
}

QString ApplicationModel::user()
{
    return m_username;
}

QString ApplicationModel::password()
{
    return m_password;
}

bool ApplicationModel::logined()
{
    return m_isLogined;
}

void ApplicationModel::send()
{
    QtConcurrent::run([this]{
        commit();
    });
}

void ApplicationModel::commit()
{
    emit requestLaunch();

    QtSoapMessage message;
    message.setMethod("Login", "http://localhost/");
    message.addMethodArgument("userno", "", m_username);
    message.addMethodArgument("password", "", m_password);

    m_http->setAction("http://localhost/Login");
    m_http->setHost("180.153.158.111", false, 88);
    m_http->submitRequest(message, "/assets.asmx");

    qDebug() << "message:" << message.toXmlString();
}

void ApplicationModel::onResponseReady(const QtSoapMessage &response)
{
    qDebug() << "onResponseReady";

    QString strXML = response.toXmlString();
    qDebug() << "\nonResponseReady: strXML: " << strXML;

    QDomDocument doc;
    doc.setContent(strXML);

    QDomNodeList nodeList = doc.elementsByTagName("LoginResult");
    if (!nodeList.isEmpty())
    {
        QDomNode node = nodeList.at(0);
        QString strResult = node.toElement().text();
        m_isLogined = strResult == "Y" ? true: false;
        qDebug() << "strResult:" << strResult;
    }

    emit requestFinish();
}
