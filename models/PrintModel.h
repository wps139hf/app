#ifndef PRINTMODEL_H
#define PRINTMODEL_H

#include "AbstractModel.h"

class PrintModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit PrintModel(QObject *parent = nullptr);

protected:
    void init();
    void handleRequest();
};

#endif // PRINTMODEL_H
