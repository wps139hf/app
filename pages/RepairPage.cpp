#include "RepairPage.h"
#include "ui_RepairPage.h"

RepairPage::RepairPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RepairPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RepairPage::~RepairPage()
{
    delete ui;
}

void RepairPage::init()
{
    setTitle(tr("报修信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
