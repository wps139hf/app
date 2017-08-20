#include "AssetInfo.h"
#include "ui_AssetInfo.h"
#include "ModelManager.h"

AssetInfo::AssetInfo(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetInfo)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

AssetInfo::~AssetInfo()
{
    delete ui;
}

void AssetInfo::init()
{
    setTitle(tr("资产信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);

    AssetModel *model = ModelManager::instance()->asset();
    Asset *asset = model->getAsset();
    if(asset){
        ui->serialNum->setText(asset->serialNum);
        ui->name->setText(asset->name);
        ui->classification->setText(asset->classification);
        ui->qrCode->setText(asset->qrCode);
        ui->department->setText(asset->department);
        ui->storage->setText(asset->storage);
        ui->state->setText(asset->state);
        ui->spec->setText(asset->specification);
        ui->dateOfPurchase->setText(asset->dateOfPurchase);
        ui->dateOfStorage->setText(asset->dateOfStorage);
    }
}
