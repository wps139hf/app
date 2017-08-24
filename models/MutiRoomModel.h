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
    QJsonObject object(const QString &sn);
    JsonMap map();
    int size();
    void setCurrentObject(const QJsonObject &object);
    QJsonObject currentObject();
protected:
    void init();
    void handleRequest();
private:
    QString m_username;
    MultiRoom m_room;
    QList<QJsonObject> m_objectList;
    JsonMap m_mapBySN;
    QJsonObject m_currentObject;
};

#endif // MUTIROOMMODEL_H
