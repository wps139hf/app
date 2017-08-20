#include "CarModel.h"

CarModel::CarModel(QObject *parent)
    : AbstractModel(parent)
{

}

void CarModel::handleRequest()
{
    setRequestMethod("GetUseCardList");
    addRequestArg("topQuantity", "1");
    addRequestArg("userNo", "sa");
    sendRequest();
}

void CarModel::handleResponse()
{

}
