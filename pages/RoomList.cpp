#include "RoomList.h"
#include "ui_RoomList.h"
#include "ModelManager.h"
#include "ListItem.h"

#include <QVBoxLayout>

RoomList::RoomList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RoomList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);

    m_vLayout = new QVBoxLayout;
    m_vLayout->setContentsMargins(10, 20, 10, 20);

    ui->tray->setLayout(m_vLayout);
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
            QString info = applicant + " " + dateOfUse + " " + timeOfUse + " 申请单";
            ListItem *listItem = new ListItem(info, key, this);

            connect(listItem, &ListItem::itemselected, [this, model](const QString &key){
                qDebug() << "key=" << key;
                model->setCurrentObject(model->object(key));
                emit itemSelected();
            });

            m_vLayout->addWidget(listItem, 1);
            m_vLayout->addStretch(2);
        }
    }
}

void RoomList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + ui->label->height();
    ui->tray->setGeometry(0, y, width(), height() - y);
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

