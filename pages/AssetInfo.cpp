#include "AssetInfo.h"
#include "ui_AssetInfo.h"

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
}
