#include "MainPages.h"
#include "ui_MainPages.h"

MainPages::MainPages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPages)
{
    ui->setupUi(this);
    ui->pageMsg->hide();
    ui->pageHome->hide();
    ui->pageMine->hide();

    initConnections();
}

MainPages::~MainPages()
{
    delete ui;
}

void MainPages::setTitleBar(TitleBar *bar)
{
    ui->pageMsg->setTitleBar(bar);
    ui->pageHome->setTitleBar(bar);
    ui->pageMine->setTitleBar(bar);
}

void MainPages::setToolBar(ToolBar *bar)
{
    ui->pageMsg->setToolBar(bar);
    ui->pageHome->setToolBar(bar);
    ui->pageMine->setToolBar(bar);
}

void MainPages::showMsg()
{
    showPage(ui->pageMsg);
}

void MainPages::showHome()
{
    showPage(ui->pageHome);
}

void MainPages::showMine()
{
    showPage(ui->pageMine);
}

void MainPages::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->pageMsg->resize(width(), height());
    ui->pageHome->resize(width(), height());
    ui->pageMine->resize(width(), height());
}

void MainPages::showPage(QWidget *page)
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

void MainPages::initConnections()
{
    connect(ui->pageMsg, &MessagePage::backClicked, [this](bool){
        ui->pageHome->show();
    });

    connect(ui->pageMine, &MinePage::backClicked, [this](bool){
        ui->pageHome->show();
    });
}
