#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>
#include "ApplicationModel.h"

class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);
    ApplicationModel *application();

    static ModelManager *instance();
signals:
    void requestLaunch();
    void requestFinish();
private:
    static ModelManager *m_instance;
};

#endif // MODELMANAGER_H
