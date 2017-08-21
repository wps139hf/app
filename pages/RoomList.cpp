#include "RoomList.h"
#include "ui_RoomList.h"

RoomList::RoomList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RoomList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RoomList::~RoomList()
{
    delete ui;
}

void RoomList::init()
{
    setTitle(tr("多功能厅信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RoomList::updatePage()
{

}
