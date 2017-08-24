#ifndef REPAIRMODEL_H
#define REPAIRMODEL_H

#include "AbstractModel.h"

class RepairModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit RepairModel(QObject *parent = nullptr);

protected:
    void init();
    void handleRequest();
private:
    QList<QJsonObject> m_objectList;
    QString m_username;
    JsonMap m_mapBySN;
};

#endif // REPAIRMODEL_H
