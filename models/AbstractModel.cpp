#include "AbstractModel.h"
#include "ModelManager.h"

AbstractModel::AbstractModel(QObject *parent) : QObject(parent)
{
    ModelManager *manager = qobject_cast<ModelManager*>(parent);
    if(manager){
        connect(this, SIGNAL(requestLaunch()), manager, SIGNAL(requestLaunch()));
        connect(this, SIGNAL(requestFinish()), manager, SIGNAL(requestFinish()));
    }

    m_soap = new SoapMessage(this);
}

void AbstractModel::request()
{
    emit requestLaunch();

    init();
    handleRequest();

    m_errorMsg = m_soap->getValueByTag("msg");
    emit requestFinish();
}

QString AbstractModel::errorMsg()
{
    return m_errorMsg;
}

void AbstractModel::init()
{

}

void AbstractModel::handleRequest()
{

}
