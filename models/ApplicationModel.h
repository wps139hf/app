#ifndef APPLICATIONMODEL_H
#define APPLICATIONMODEL_H

#include <QObject>
#include <QFutureWatcher>
#include <QFuture>

#include "qtsoap.h"

class ApplicationModel : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationModel(QObject *parent = nullptr);
    void setUser(const QString &user);
    void setPassword(const QString &password);

    QString user();
    QString password();
    bool logined();

    void send();
    void commit();
signals:
    void requestLaunch();
    void requestFinish();
public slots:
    void onResponseReady(const QtSoapMessage &response);
private:
    QString m_username;
    QString m_password;
    bool m_isLogined = false;

    QtSoapHttpTransport *m_http = Q_NULLPTR;
};

#endif // APPLICATIONMODEL_H
