#include "PageManager.h"
#include "ui_PageManager.h"

PageManager::PageManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageManager)
{
    ui->setupUi(this);
    ui->pageMsg->hide();
    ui->pageHome->hide();
    ui->pageMine->hide();

    initConnections();
}

PageManager::~PageManager()
{
    delete ui;
}

void PageManager::setTitleBar(TitleBar *bar)
{
    ui->pageMsg->setTitleBar(bar);
    ui->pageHome->setTitleBar(bar);
    ui->pageMine->setTitleBar(bar);
}

void PageManager::setToolBar(ToolBar *bar)
{
    ui->pageMsg->setToolBar(bar);
    ui->pageHome->setToolBar(bar);
    ui->pageMine->setToolBar(bar);
}

void PageManager::showMsg()
{
    showPage(ui->pageMsg);
}

void PageManager::showHome()
{
    showPage(ui->pageHome);
}

void PageManager::showMine()
{
    showPage(ui->pageMine);
}

MessagePage *PageManager::messagePage()
{
    return ui->pageMsg;
}

HomePage *PageManager::homePage()
{
    return ui->pageHome;
}

MinePage *PageManager::minePage()
{
    return ui->pageMine;
}

void PageManager::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->pageMsg->resize(width(), height());
    ui->pageHome->resize(width(), height());
    ui->pageMine->resize(width(), height());
}

void PageManager::showPage(QWidget *page)
{
    for(auto child : children()){
        QWidget *w = qobject_cast<QWidget*>(child);
        if(w){
            if(w == page){
                page->show();
            }else{
                w->hide();
            }
        }
    }
}

void PageManager::initConnections()
{
    connect(ui->pageMsg, &MessagePage::backClicked, [this](bool){
        ui->pageHome->show();
    });

    connect(ui->pageMine, &MinePage::backClicked, [this](bool){
        ui->pageHome->show();
    });
}
