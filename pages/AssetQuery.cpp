#include "AssetQuery.h"
#include "ui_AssetQuery.h"

#include "ModelManager.h"

AssetQuery::AssetQuery(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetQuery)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);

    AssetModel *model = ModelManager::instance()->asset();
    connect(model, &AssetModel::requestFinish, [this, model](){
        hideBusyPage();

        if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
            emit showInfo();
            model->getAsset()->debug("ASSET");
            qDebug() << "toJsonString:" << model->getAsset()->toJsonString();
        }else{
            qDebug() << "Error:"<< model->errorMsg();
        }
    });
}

AssetQuery::~AssetQuery()
{
    delete ui;
}

void AssetQuery::init()
{
    setTitle(tr("资产查询"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void AssetQuery::on_btnOk_clicked()
{
    showBusyPage();

    AssetModel *model = ModelManager::instance()->asset();
    model->setNumber(ui->lineEdit->text());
    model->commit();
}
