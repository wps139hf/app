#include "AssetModel.h"


AssetModel::AssetModel(QObject *parent)
    : AbstractModel(parent)
{

}

void AssetModel::handleRequest()
{
    setRequestMethod("GetAsset");
    addRequestArg("barcode", "");
    sendRequest();
}

void AssetModel::handleResponse()
{
    getValueByTag("GetAssetResult");
    m_errorMsg = getValueByTag("msg");
}
