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

void MessagePage::showEvent(QShowEvent *e)
{
    BasePage::showEvent(e);
    setTitle(tr("消息"));
    qDebug() << objectName() << "show up.";
}
