#include "RoomList.h"
#include "ui_RoomList.h"
#include "ModelManager.h"

RoomList::RoomList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RoomList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RoomList::~RoomList()
{
    delete ui;
}

void RoomList::init()
{
    setTitle(tr("多功能厅信息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RoomList::refresh()
{
    MutiRoomModel *model = ModelManager::instance()->multiRoom();
    if(model){
        JsonMap jsonMap = model->map();
        for(auto key : jsonMap.keys()){
            QJsonObject object = jsonMap.value(key);
            QString applicant = object.value("申请人").toString();
            QString dateOfUse = object.value("使用日期").toString();
            QString timeOfUse = object.value("使用开始").toString();
            QString label = QString("申请记录：") + key + "-" + applicant + " "
                    + dateOfUse + " " + timeOfUse;
            ui->list->addItem(label);
        }
    }
}
