#ifndef ASSETMODEL_H
#define ASSETMODEL_H

#include "AbstractModel.h"
class AssetModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit AssetModel(QObject *parent = nullptr);
protected:
    void handleRequest();
    void handleResponse();
};

#endif // ASSETMODEL_H
