#ifndef APPLICATIONMODEL_H
#define APPLICATIONMODEL_H

#include <QObject>
#include <QFutureWatcher>
#include <QFuture>

#include "AbstractModel.h"

class ApplicationModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit ApplicationModel(QObject *parent = nullptr);
    void setUser(const QString &user);
    void setPassword(const QString &password);
    void setLogin(bool enable);
    QString user();
    QString password();
    bool logined();
    bool valid();
protected:
    void handleRequest();
private:
    QString m_username;
    QString m_password;
    bool m_isLogined = false;
    bool m_isUserValid = false;
};

#endif // APPLICATIONMODEL_H
