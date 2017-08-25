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
    addItems(ModelManager::instance()->multiRoom()->pendingMap());
    addItems(ModelManager::instance()->multiRoom()->doneMap());
}

void RoomList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + ui->label->height();
    ui->tray->setGeometry(10, y, width() - 20, height() - y);
    ui->list->setGeometry(5, 5, ui->tray->width() - 10, ui->tray->height() - 10);
}

bool RoomList::contains(int index)
{
    for(auto item : m_keyList){
        if(item == index){
            return true;
        }
    }
    return false;
}

void RoomList::addItems(const JsonObjectMap &map)
{
    for(auto index : map.keys()){
        if(contains(index)){
            continue;
        }
        m_keyList.append(index);

        QJsonObject object = map.value(index);
        QString applicant = object.value("申请人").toString();
        QString dateOfUse = object.value("使用日期").toString();
        QString timeOfUse = object.value("使用开始").toString();
        QString info = applicant + " " + dateOfUse + " " + timeOfUse + " 申请单";

        ListItem *item = new ListItem(info, index, this);

        connect(item, &ListItem::itemselected, [this](int index){
            ModelManager::instance()->multiRoom()->setCurrentObject(index);
            emit itemSelected();
        });

        ui->list->addItem(item, QSize(ui->list->width(), item->height()));
    }
}

