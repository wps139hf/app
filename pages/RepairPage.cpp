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
#if 0
    QJsonObject object = ModelManager::instance()->car()->currentObject();
    ui->applicant->setText(object.value("申请人").toString());
    ui->serialNum->setText(object.value("编号").toString());
    ui->peoples->setText(QString().setNum(object.value("乘车人数").toInt()));
    ui->destination->setText(object.value("目的地").toString());
    ui->trip->setText(object.value("单程").toString() == "是" ? "单程" : "双程");
    ui->timeOfUse->setText(object.value("出车时间").toString());
    ui->comment->setText(object.value("用车说明").toString());
    ui->agreeable->setText(object.value("审批状态").toString());
#endif
}
