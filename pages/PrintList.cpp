#include "PrintList.h"
#include "ui_PrintList.h"
#include "ListItem.h"

PrintList::PrintList(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::PrintList)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
    connect(ui->requestBtn,SIGNAL(pressed()),this,SIGNAL(request()));
}

PrintList::~PrintList()
{
    delete ui;
}

void PrintList::init()
{
    setTitle(tr("文印申请"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void PrintList::refresh()
{
    addItems(ModelManager::instance()->print()->pendingMap());
    addItems(ModelManager::instance()->print()->doneMap());
}

void PrintList::resizeEvent(QResizeEvent *e)
{
    AnimatedPage::resizeEvent(e);
    ui->titleBar->setGeometry(0, 0, width(), ui->titleBar->height());

    int y = ui->titleBar->height() + 20;
    ui->tray->setGeometry(10, y, width() - 20, height() - y);
    ui->list->setGeometry(5, 5, ui->tray->width() - 10, ui->tray->height() - 10);
}

bool PrintList::contains(int key)
{
    for(auto item : m_keyList){
        if(item == key){
            return true;
        }
    }
    return false;
}

void PrintList::addItems(const JsonObjectMap &map)
{
    for(auto index : map.keys()){
        if(contains(index)){
            continue;
        }
        m_keyList.append(index);

        QJsonObject object = map.value(index);
        QString applicant = object.value("送印人").toString();
        QString date = object.value("送印时间").toString();
        QString info = applicant + " " + date;

        ListItem *item = new ListItem(info, index, this);
        ui->list->addItem(item, QSize(ui->list->width(), item->height()));
        connect(item, &ListItem::itemselected, [this](int index){
            ModelManager::instance()->print()->setCurrentObject(index);
            emit itemSelected();
        });
    }
}
