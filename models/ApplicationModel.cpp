#include "ApplicationModel.h"
#include "ModelManager.h"

#include <QtConcurrent>

ApplicationModel::ApplicationModel(QObject *parent)
    : AbstractModel(parent)
{
    m_isLogined = m_setting.value("isLogined", false).toBool();
    m_username = m_setting.value("username", "").toString();
}

void ApplicationModel::setUser(const QString &user)
{
    m_username = user;
    m_setting.setValue("username", user);
}

void ApplicationModel::setPassword(const QString &password)
{
    m_password = password;
}

void ApplicationModel::setLogin(bool enable)
{
    m_isLogined = enable;
    m_setting.setValue("isLogined", enable);
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

bool ApplicationModel::valid()
{
    return m_isUserValid;
}

void ApplicationModel::handleRequest()
{
    m_soap->setRequestMethod("Login");
    m_soap->addRequestArg("userno", m_username);
    m_soap->addRequestArg("password", m_password);
    m_soap->submit();

    m_isUserValid = m_soap->getValueByTag("LoginResult") == "true" ? true : false;
    m_errorMsg = m_soap->getValueByTag("msg");
    qDebug() << "LoginResult:" << m_soap->getValueByTag("LoginResult");
    qDebug() << "username:" << m_soap->getValueByTag("username");
    qDebug() << "msg:" << errorMsg();
}
