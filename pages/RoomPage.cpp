#include "RoomPage.h"
#include "ui_RoomPage.h"

RoomPage::RoomPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RoomPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RoomPage::~RoomPage()
{
    delete ui;
}

void RoomPage::init()
{
    setTitle(tr("多功能厅信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
