#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QAuthenticator>

class Http : public QObject
{
    Q_OBJECT
public:
    explicit Http(QObject *parent = nullptr);

    void startRequest(const QUrl &requestedUrl);
    QString content();

    void setAuthenticator(const QAuthenticator &auth);

    static Http &instance();
signals:
    void finished();
public slots:
    void onAuthenticationRequired(QNetworkReply *, QAuthenticator *);
    void onSslErrors(QNetworkReply*reply, const QList<QSslError>&errors);
    void onReplyFinished();
    void onReadyRead();
private:
    QAuthenticator m_authenticator;
    QUrl m_url;
    QNetworkAccessManager m_qnam;
    QNetworkReply *m_reply = Q_NULLPTR;

    QString m_content;
};

#endif // HTTP_H
