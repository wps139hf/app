#ifndef ASSETMODEL_H
#define ASSETMODEL_H

#include "AbstractModel.h"
#include "AbstractData.h"

class Asset : public AbstractData
{
public:
    QString serialNum = "1111";
    QString name = "222";
    QString classification = "333";
    QString qrCode = "444";
    QString department = "555";
    QString storage = "666";
    QString state = "777";
    QString specification = "888";
    QString dateOfPurchase = "999";
    QString dateOfStorage = "000";

public:
    explicit Asset();
    QJsonObject toJson();
    void fromJson(const QJsonObject &object);
    void debug(const QString &tag);

    QString toJsonString();
    bool fromJsonString(const QString &jsonString);
};

class AssetModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit AssetModel(QObject *parent = nullptr);
    void setNumber(const QString &number);
    Asset *getAsset();
    QString info();
protected:
    void handleRequest();
    void handleResponse();
private:
    QString m_number;
    Asset m_asset;
    QString m_info;
};

#endif // ASSETMODEL_H
