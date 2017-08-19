#include <QUrl>
#include <QNetworkReply>
#include <QMessageBox>

Http::Http(QObject *parent) : QObject(parent)
{
    connect(&m_qnam, &QNetworkAccessManager::authenticationRequired,
            this, &Http::onAuthenticationRequired);

    connect(&m_qnam, &QNetworkAccessManager::sslErrors,
            this, &onSslErrors);
}

void Http::startRequest(const QUrl &requestedUrl)
{
    qDebug() << "username:" << m_authenticator.user();
    qDebug() << "password:" << m_authenticator.password();
    qDebug() << "requestedUrl:" << requestedUrl.toString();

    emit started();

    m_content.clear();

    m_url = requestedUrl;

    m_reply = m_qnam.get(QNetworkRequest(requestedUrl));
    connect(m_reply, &QNetworkReply::finished, this, &Http::onReplyFinished);
    connect(m_reply, &QNetworkReply::readyRead, this, &Http::onReadyRead);
}

QString Http::content()
{
    return m_content;
}

void Http::setAuthenticator(const QAuthenticator &auth)
{
    m_authenticator = auth;
}

Http &Http::instance()
{
    static Http _http;
    return _http;
}

void Http::onAuthenticationRequired(QNetworkReply *, QAuthenticator *auth)
{
    *auth = m_authenticator;
}

void Http::onSslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    QString errorString;
    for(auto error : errors){
        if(!errorString.isEmpty()){
            errorString += "\n";
        }
        errorString += error.errorString();
    }

    qDebug() << "onSslErrors:" << errorString;
}

void Http::onReplyFinished()
{
    emit finished();

    qDebug() << m_content;

    if(m_reply->error()){
        //弹出error页面

        m_reply->deleteLater();
        m_reply = Q_NULLPTR;
        return;
    }

    const QVariant redirectTarget = m_reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    m_reply->deleteLater();
    m_reply = Q_NULLPTR;

    if(!redirectTarget.isNull()){
        const QUrl redirectUrl = m_url.resolved(redirectTarget.toUrl());
        startRequest(redirectUrl);
    }
}

void Http::onReadyRead()
{
    m_content.append(m_reply->readAll());
}
