#include "MinePage.h"
#include "ui_MinePage.h"

MinePage::MinePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::MinePage)
{
    ui->setupUi(this);
}

MinePage::~MinePage()
{
    delete ui;
}

void MinePage::init()
{
    setTitle(tr("我的信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
    setToolButtonChecked(ToolBar::Mine);
}
