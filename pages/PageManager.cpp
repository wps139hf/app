#include "PageManager.h"
#include "ui_PageManager.h"

PageManager::PageManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageManager)
{
    ui->setupUi(this);

    initPageList();
    initToolBar();
    initConnections();

    hidePages();
}

PageManager::~PageManager()
{
    delete ui;
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

void PageManager::sendNotification(const QString &notification)
{
    emit notified(notification);
}

void PageManager::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    for(auto page : m_pageList){
        page->resize(width(), height() - ui->toolBar->height());
        page->move(0, 0);
    }

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
}

void PageManager::initPageList()
{
    m_pageList.append(ui->pageMsg);
    m_pageList.append(ui->pageHome);
    m_pageList.append(ui->pageMine);
}

void PageManager::initToolBar()
{
    for(auto page : m_pageList){
        BasePage *w = qobject_cast<BasePage*>(page);
        if(w){
            w->setToolBar(ui->toolBar);
        }
    }
}

void PageManager::hidePages()
{
    for(auto page : m_pageList){
        page->hide();
    }
}

void PageManager::showPage(QWidget *page)
{
    page->show();
    raise();
    for(auto p : m_pageList){
        if(p != page){
            p->hide();
        }
    }
}

void PageManager::initConnections()
{
    connect(ui->toolBar, &ToolBar::clicked, [this](int btnIndex){
        qDebug() << "toolbar: clicked:" << btnIndex;
        switch (btnIndex) {
        case ToolBar::Message:
//            showPage(ui->pageMsg);
            sendNotification("功能正在开发中");
            break;
        case ToolBar::Home:
            showPage(ui->pageHome);
            break;
        case ToolBar::Mine:
            showPage(ui->pageMine);
            break;
        default:
            break;
        }
    });

    connect(ui->pageMsg, &MessagePage::backClicked, [this](bool){
        showPage(ui->pageHome);
    });

    connect(ui->pageMine, &MinePage::backClicked, [this](bool){
        showPage(ui->pageHome);
    });
}
