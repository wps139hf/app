#include "PrintList.h"
#include "ui_PrintList.h"

PrintList::PrintList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::PrintList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

PrintList::~PrintList()
{
    delete ui;
}

void PrintList::init()
{
    setTitle(tr("文印申请信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void PrintList::refresh()
{

}
