#include "BuyList.h"
#include "ui_BuyList.h"
#include "ListItem.h"

BuyList::BuyList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::BuyList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

BuyList::~BuyList()
{
    delete ui;
}

void BuyList::init()
{
    setTitle(tr("请购申请"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void BuyList::refresh()
{
    addItems(ModelManager::instance()->buy()->pendingMap());
    addItems(ModelManager::instance()->buy()->doneMap());
}

void BuyList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + 20;
    ui->tray->setGeometry(10, y, width() - 20, height() - y);
    ui->list->setGeometry(5, 5, ui->tray->width() - 10, ui->tray->height() - 10);
}

bool BuyList::contains(int key)
{
    for(auto item : m_keyList){
        if(item == key){
            return true;
        }
    }
    return false;
}

void BuyList::addItems(const JsonObjectMap &map)
{
    for(auto index : map.keys()){
        if(contains(index)){
            continue;
        }
        m_keyList.append(index);

        QJsonObject object = map.value(index);
        QString applicant = object.value("审请人").toString();
        QString date = object.value("申请时间").toString();
        QString theme = object.value("采购主题").toString();
        QString info = applicant + " " + date + " " + theme;

        ListItem *item = new ListItem(info, index, this);
        ui->list->addItem(item, QSize(ui->list->width(), item->height()));
        connect(item, &ListItem::itemselected, [this](int index){
            ModelManager::instance()->buy()->setCurrentObject(index);
            emit itemSelected();
        });
    }
}
