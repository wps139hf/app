#include "BuyList.h"
#include "ui_BuyList.h"

BuyList::BuyList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::BuyList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

BuyList::~BuyList()
{
    delete ui;
}

void BuyList::init()
{
    setTitle(tr("请购申请信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void BuyList::refresh()
{

}
