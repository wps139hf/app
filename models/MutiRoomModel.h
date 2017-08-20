#ifndef MUTIROOMMODEL_H
#define MUTIROOMMODEL_H

#include "AbstractModel.h"
#include "AbstractData.h"

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
protected:
    void handleRequest();
    void handleResponse();
private:
    MultiRoom m_room;
};

#endif // MUTIROOMMODEL_H
