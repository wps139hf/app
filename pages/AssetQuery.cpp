#include "AssetQuery.h"
#include "ui_AssetQuery.h"

#include "ModelManager.h"

AssetQuery::AssetQuery(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetQuery)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);
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
    AssetModel *model = ModelManager::instance()->asset();
    model->setNumber(ui->lineEdit->text());
    model->request();

    if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
        emit showInfo();
        model->getAsset()->debug("ASSET");
    }else{
        sendNotification(model->errorMsg());
    }
}
