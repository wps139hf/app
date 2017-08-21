#ifndef JSON_H
#define JSON_H

#include <QObject>
#include <QJsonObject>

class JSON : public QObject
{
    Q_OBJECT
public:
    explicit JSON(QObject *parent = nullptr);
    static QJsonObject toObject(const QString &jsonString);
};

#endif // JSON_H
