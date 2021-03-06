#ifndef ASSETMODEL_H
#define ASSETMODEL_H

#include "AbstractModel.h"
#include "AbstractData.h"

class Asset : public AbstractData
{
public:
    QString serialNum = "";
    QString name = "";
    QString classification = "";
    QString qrCode = "";
    QString department = "";
    QString storage = "";
    QString state = "";
    QString specification = "";
    QString dateOfPurchase = "";
    QString dateOfStorage = "";

public:
    explicit Asset();
    void debug(const QString &tag);
protected:
    QJsonObject toJson();
    void fromJson(const QJsonObject &object);
};

class AssetModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit AssetModel(QObject *parent = nullptr);
    void setNumber(const QString &number);
    Asset *getAsset();
protected:
    void handleRequest();
private:
    QString m_number;
    Asset m_asset;
};

#endif // ASSETMODEL_H
