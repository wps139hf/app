#include "RoomList.h"
#include "ui_RoomList.h"
#include "ModelManager.h"
#include "ListItem.h"

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
            if(contains(key)){
                continue;
            }
            m_keyList.append(key);
            QJsonObject object = jsonMap.value(key);
            QString applicant = object.value("申请人").toString();
            QString dateOfUse = object.value("使用日期").toString();
            QString timeOfUse = object.value("使用开始").toString();
//            QString info = QString("申请记录：") + key + "-" + applicant + " "
//                    + dateOfUse + " " + timeOfUse;
            QString info = applicant + " " + dateOfUse + " " + timeOfUse + " 申请单";
            ListItem *listItem = new ListItem(info, key, this);

            connect(listItem, &ListItem::itemselected, [this, model](const QString &key){
                qDebug() << "key=" << key;
                model->setCurrentObject(model->object(key));
                emit itemSelected();
            });

            ui->verticalLayout->addWidget(listItem);
            ui->verticalLayout->addStretch(2);
        }
    }
}

bool RoomList::contains(const QString &key)
{
    for(auto item : m_keyList){
        if(item == key){
            return true;
        }
    }
    return false;
}

