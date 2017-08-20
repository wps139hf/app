#include "AssetModel.h"
#include <QDebug>

Asset::Asset():AbstractData()
{
}

QJsonObject Asset::toJson()
{
    QJsonObject json{
        {"资产编号", serialNum},
        {"资产名称", name},
        {"资产分类", classification},
        {"资产条码", qrCode},
        {"使用部门", department},
        {"存放地", storage},
        {"资产状态", state},
        {"规格", specification},
        {"采购日期", dateOfPurchase},
        {"入库日期", dateOfStorage}
    };
    return json;
}

void Asset::fromJson(const QJsonObject &object)
{
    if(object.isEmpty()){
        return;
    }

    serialNum = object.value("资产编号").toString();
    name = object.value("资产名称").toString();
    classification = object.value("资产分类").toString();
    qrCode = object.value("资产条码").toString();
    department = object.value("使用部门").toString();
    storage = object.value("存放地").toString();
    state = object.value("资产状态").toString();
    specification = object.value("规格").toString();
    dateOfPurchase = object.value("采购日期").toString();
    dateOfStorage = object.value("入库日期").toString();
}

void Asset::debug(const QString &tag)
{
    qDebug() << tag << ":\n"
             << "资产编号:" << serialNum << "\n"
             << "资产名称:" << name << "\n"
             << "资产分类:" << classification << "\n"
             << "资产条码:" << qrCode << "\n"
             << "使用部门:" << department << "\n"
             << "存放地:" << storage << "\n"
             << "资产状态:" << state << "\n"
             << "规格:" << specification << "\n"
             << "采购日期:" << dateOfPurchase << "\n"
             << "入库日期:" << dateOfStorage;
}

AssetModel::AssetModel(QObject *parent)
    : AbstractModel(parent)
{

}

void AssetModel::setNumber(const QString &number)
{
    m_number = number;
}

Asset *AssetModel::getAsset()
{
    return &m_asset;
}

void AssetModel::handleRequest()
{
    setRequestMethod("GetAsset");
    addRequestArg("barcode", m_number);
    sendRequest();
}

void AssetModel::handleResponse()
{
    m_asset.fromJsonString(getValueByTag("GetAssetResult"));
    m_errorMsg = getValueByTag("msg");
}
