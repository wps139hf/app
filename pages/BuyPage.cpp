#include "BuyPage.h"
#include "ui_BuyPage.h"

BuyPage::BuyPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::BuyPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

BuyPage::~BuyPage()
{
    delete ui;
}

void BuyPage::init()
{
    setTitle(tr("请购信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
