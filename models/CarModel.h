#ifndef CARMODEL_H
#define CARMODEL_H

#include "AbstractModel.h"

class CarModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit CarModel(QObject *parent = nullptr);

protected:
    void handleRequest();
    void handleResponse();
private:
};

#endif // CARMODEL_H