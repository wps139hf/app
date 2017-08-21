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
    MutiRoomModel *model = ModelManager::instance()->multiRoom();
    if(model){
        ui2->applicant->setText(model->value("申请人").toString());
        ui2->serialNum->setText(model->value("编号").toString());
        ui2->peoples->setText(model->value("使用人数").toString());
        ui2->deskAndChair->setText(model->value("桌椅要求").toString());

        QString date = model->value("使用日期").toString();
        QString timeStart = model->value("使用开始").toString();
        QString timeEnd = model->value("使用结束").toString();
        ui2->timeOfUse->setText(date + "  " + timeStart + "--" + timeEnd);

        ui2->purpose->setText(model->value("使用目的").toString());

        QString demands;
        QStringList list;
        list << "一体机" << "摄像" << "笔记本" << "幕布";
        for(auto item : list){
            QString use = model->value(item).toString();
            if(use == "Y"){
                if(!demands.isEmpty()){
                    demands += ", ";
                }
                demands += item;
            }
        }
        ui2->demands->setText(demands);

        ui2->agreeable->setText(model->value("审批状态").toString());
    }
}
