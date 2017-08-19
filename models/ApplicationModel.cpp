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

void ApplicationModel::commit()
{
    AbstractModel::commit();
    setRequestMethod("Login");
    addRequestArg("userno", m_username);
    addRequestArg("password", m_password);
    postRequest();
}

void ApplicationModel::handleResponse()
{
    m_isLogined = getValueByTag("LoginResult") == "true" ? true : false;

    qDebug() << "LoginResult:" << getValueByTag("LoginResult");
    qDebug() << "username:" << getValueByTag("username");
    qDebug() << "msg:" << getValueByTag("msg");
}
