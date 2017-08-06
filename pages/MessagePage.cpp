#include "MessagePage.h"
#include "ui_MessagePage.h"

MessagePage::MessagePage(QWidget *parent)
    : BasePage(parent)
    , ui(new Ui::MessagePage)
{
    ui->setupUi(this);
}

MessagePage::~MessagePage()
{
    delete ui;
}

void MessagePage::init()
{
    setTitle(tr("消息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
    setToolButtonChecked(ToolBar::Message);
}
