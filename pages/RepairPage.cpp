#include "RepairPage.h"
#include "ui_RepairPage.h"
#include "ModelManager.h"

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
    setTitle(tr("报修申请单"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RepairPage::refresh()
{
    QJsonObject object = ModelManager::instance()->repair()->currentObject();
    ui->applicant->setText(object.value("报修人").toString());
    ui->serialNum->setText(object.value("维修编号").toString());
    ui->time->setText(object.value("报修时间").toString());
    ui->classroom->setText(object.value("班级、专用室").toString());
    ui->content->setText(object.value("报修内容").toString());
    ui->status->setText(object.value("完成情况").toString());
    ui->staff->setText(object.value("维修人").toString());
    ui->agreeable->setText(object.value("审批状态").toString());
}
