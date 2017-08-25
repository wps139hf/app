#ifndef APPBASEMODEL_H
#define APPBASEMODEL_H

#include "AbstractModel.h"

typedef QMap<int, QJsonObject> JsonObjectMap;

class AppBaseModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit AppBaseModel(QObject *parent = nullptr);
    void setCurrentObject(int index);
    QJsonObject currentObject();
    JsonObjectMap pendingMap();
    JsonObjectMap doneMap();
protected:
    void init() override;
    void handleRequest() override;
    void outputObject();

    virtual void getQuantity();
    virtual void getList();
    virtual void filterObjects();
protected:
    int m_count = 0;
    QString m_username;
    QList<QJsonObject> m_objectList;
    JsonObjectMap m_pendingMap;
    JsonObjectMap m_doneMap;
    QJsonObject m_currentObject;
};

#endif // APPBASEMODEL_H
