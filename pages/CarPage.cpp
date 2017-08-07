#include "CarPage.h"
#include "ui_CarPage.h"

CarPage::CarPage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::CarPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);

}

CarPage::~CarPage()
{
    delete ui;
}

void CarPage::init()
{
    setTitle(tr("用车信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
