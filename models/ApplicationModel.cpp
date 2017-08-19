#include "ApplicationModel.h"
#include "ModelManager.h"

#include <QtConcurrent>

ApplicationModel::ApplicationModel(QObject *parent)
    : AbstractModel(parent)
{
}

void ApplicationModel::setUser(const QString &user)
{
    m_username = user;
}

void ApplicationModel::setPassword(const QString &password)
{
    m_password = password;
}

void ApplicationModel::setLogin(bool enable)
{
    m_isLogined = enable;
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
    setRequestMethod("Login");
    addRequestArg("userno", m_username);
    addRequestArg("password", m_password);
    sendRequest();
}

void ApplicationModel::handleResponse()
{
    m_isUserValid = getValueByTag("LoginResult") == "true" ? true : false;
    m_errorMsg = getValueByTag("msg");
    qDebug() << "LoginResult:" << getValueByTag("LoginResult");
    qDebug() << "username:" << getValueByTag("username");
    qDebug() << "msg:" << getValueByTag("msg");
}
