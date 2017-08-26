#include "RoomPage.h"
#include "ui_RoomPage2.h"
#include "ModelManager.h"

RoomPage::RoomPage(QWidget *parent) :
    AnimatedPage(parent),
    ui2(new Ui::RoomPage2)
{
    ui2->setupUi(this);
    setTitleBar(ui2->titleBar);
}

RoomPage::~RoomPage()
{
    delete ui2;
}

void RoomPage::init()
{
    setTitle(tr("多功能厅申请单"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RoomPage::refresh()
{
    QJsonObject object = ModelManager::instance()->multiRoom()->currentObject();
    ui2->applicant->setText(object.value("申请人").toString());
    ui2->serialNum->setText(object.value("编号").toString());
    ui2->peoples->setText(object.value("使用人数").toString());
    ui2->deskAndChair->setText(object.value("桌椅要求").toString());

    QString date = object.value("使用日期").toString();
    QString timeStart = object.value("使用开始").toString();
    QString timeEnd = object.value("使用结束").toString();
    ui2->timeOfUse->setText(date + "  " + timeStart + "--" + timeEnd);

    ui2->purpose->setText(object.value("使用目的").toString());

    QString demands;
    QStringList list;
    list << "一体机" << "摄像" << "笔记本" << "幕布";
    for(auto item : list){
        QString use = object.value(item).toString();
        if(use == "是"){
            if(!demands.isEmpty()){
                demands += ", ";
            }
            demands += item;
        }
    }
    ui2->demands->setText(demands);

    ui2->agreeable->setText(object.value("审批状态").toString());
}
