#include "CarList.h"
#include "ui_CarList.h"
#include "ListItem.h"

CarList::CarList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::CarList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

CarList::~CarList()
{
    delete ui;
}

void CarList::init()
{
    setTitle(tr("用车申请"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void CarList::refresh()
{
    addItems(ModelManager::instance()->car()->pendingMap());
    addItems(ModelManager::instance()->car()->doneMap());
}

void CarList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + 20;
    ui->tray->setGeometry(10, y, width() - 20, height() - y);
    ui->list->setGeometry(5, 5, ui->tray->width() - 10, ui->tray->height() - 10);
}

bool CarList::contains(int key)
{
    for(auto item : m_keyList){
        if(item == key){
            return true;
        }
    }
    return false;
}

void CarList::addItems(const JsonObjectMap &map)
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
            ModelManager::instance()->car()->setCurrentObject(index);
            emit itemSelected();
        });
    }
}
