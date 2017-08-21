#ifndef MUTIROOMMODEL_H
#define MUTIROOMMODEL_H

#include "AbstractModel.h"
#include "AbstractData.h"

#include <QVariantList>

class MultiRoom : public AbstractData
{
public:
#if 0
    QString id = "";
    QString serialNum = "";
    QString applicant = "";
    QString dateUse = "";
    QString timeStart = "";
    QString timeEnd = "";
    QString purpose = "";
    QString pairsOfDeskAndChair = "";
    QString countOfPeople = "";
    bool allInOne = false;
    bool useCamera = false;
    bool useLaptop = false;
#endif
    QJsonObject data;
public:
    explicit MultiRoom();
protected:
    QJsonObject toJson();
    void fromJson(const QJsonObject &object);
};

class MutiRoomModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit MutiRoomModel(QObject *parent = nullptr);
    QJsonValue value(const QString &key) const;
    QJsonObject object(const QString &timestamp);
protected:
    void handleRequest();
private:
    MultiRoom m_room;
    QList<QJsonObject> m_objectList;
    QMap<QString, QJsonObject>m_objectMap;
};

#endif // MUTIROOMMODEL_H
