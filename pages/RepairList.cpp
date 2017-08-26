#include "RepairList.h"
#include "ui_RepairList.h"
#include "ListItem.h"

RepairList::RepairList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::RepairList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

RepairList::~RepairList()
{
    delete ui;
}

void RepairList::init()
{
    setTitle(tr("报修申请"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void RepairList::refresh()
{
    addItems(ModelManager::instance()->repair()->pendingMap());
    addItems(ModelManager::instance()->repair()->doneMap());
}

void RepairList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + 20;
    ui->tray->setGeometry(10, y, width() - 20, height() - y);
    ui->list->setGeometry(5, 5, ui->tray->width() - 10, ui->tray->height() - 10);
}

bool RepairList::contains(int key)
{
    for(auto item : m_keyList){
        if(item == key){
            return true;
        }
    }
    return false;
}

void RepairList::addItems(const JsonObjectMap &map)
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
        ui->list->addItem(item, QSize(ui->list->width(), item->height()));
        connect(item, &ListItem::itemselected, [this](int index){
            ModelManager::instance()->repair()->setCurrentObject(index);
            emit itemSelected();
        });
    }
}
