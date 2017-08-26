#include "PrintPage.h"
#include "ui_PrintPage.h"
#include "ModelManager.h"

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
    setTitle(tr("文印申请单"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void PrintPage::refresh()
{
    QJsonObject object = ModelManager::instance()->print()->currentObject();
    ui->applicant->setText(object.value("送印人").toString());
    ui->serialNum->setText(object.value("文印编号").toString());
    ui->timeOfSend->setText(object.value("送印时间").toString());
    ui->timeOfUse->setText(object.value("使用时间").toString());
    ui->paper->setText(object.value("单面复印").toString() == "是" ? "单面":"双面");
    ui->comment->setText(object.value("备注").toString());
    ui->content->setText(object.value("内容").toString());
    ui->agreeable->setText(object.value("审批状态").toString());
}
