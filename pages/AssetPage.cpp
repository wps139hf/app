#include "AssetPage.h"
#include "ui_AssetPage.h"

AssetPage::AssetPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetPage)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);
}

AssetPage::~AssetPage()
{
    delete ui;
}

void AssetPage::init()
{
    setTitle(tr("扫一扫"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
