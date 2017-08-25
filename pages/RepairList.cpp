#include "RepairList.h"
#include "ui_RepairList.h"

RepairList::RepairList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RepairList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RepairList::~RepairList()
{
    delete ui;
}

void RepairList::init()
{
    setTitle(tr("维修申请信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RepairList::refresh()
{

}
