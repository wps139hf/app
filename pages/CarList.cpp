#include "CarList.h"
#include "ui_CarList.h"

CarList::CarList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::CarList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

CarList::~CarList()
{
    delete ui;
}

void CarList::init()
{
    setTitle(tr("用车申请信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void CarList::refresh()
{

}

//void CarList::resizeEvent(QResizeEvent *e)
//{
//    AnimatedPage::resizeEvent(e);
//}
