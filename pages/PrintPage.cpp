#include "PrintPage.h"
#include "ui_PrintPage.h"

PrintPage::PrintPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::PrintPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

PrintPage::~PrintPage()
{
    delete ui;
}

void PrintPage::init()
{
    setTitle(tr("文印信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
