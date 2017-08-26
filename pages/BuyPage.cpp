#include "BuyPage.h"
#include "ui_BuyPage.h"
#include "ModelManager.h"

BuyPage::BuyPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::BuyPage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

BuyPage::~BuyPage()
{
    delete ui;
}

void BuyPage::init()
{
    setTitle(tr("请购申请单"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void BuyPage::refresh()
{
    QJsonObject object = ModelManager::instance()->buy()->currentObject();
    ui->applicant->setText(object.value("审请人").toString());
    ui->serialNum->setText(object.value("采购编号").toString());
    ui->timeOfapply->setText(object.value("采购日期").toString());
    ui->theme->setText(object.value("采购主题").toString());
    ui->timeOfBuy->setText(object.value("采购日期").toString());
    ui->agreeable->setText(object.value("审批状态").toString());
}
