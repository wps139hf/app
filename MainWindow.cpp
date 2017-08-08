#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initPageList();
    initConnections();

    hidePages();

    if(!m_isLogin){
        showPage(ui->pageWelcome);
    }else{
        showPage(ui->pageManager);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    for(auto page : m_pageList){
        page->resize(size());
        page->move(0, 0);
    }
}

void MainWindow::initPageList()
{
    m_pageList.append(ui->pageManager);

    m_pageList.append(ui->pageWelcome);
    m_pageList.append(ui->pageLogin);

    m_pageList.append(ui->pageCar);
    m_pageList.append(ui->pageRepair);
    m_pageList.append(ui->pageBuy);
    m_pageList.append(ui->pagePrint);
    m_pageList.append(ui->pageRoom);
    m_pageList.append(ui->pageAsset);
    m_pageList.append(ui->pageAssetQuery);
    m_pageList.append(ui->pageAssetInfo);
}

void MainWindow::initConnections()
{
    connect(ui->pageWelcome, &WelcomePage::loginClicked, [this]{
        showPage(ui->pageLogin);
    });

    connect(ui->pageLogin, &LoginPage::backClicked, [this]{
        showPage(ui->pageWelcome);
    });

    connect(ui->pageLogin, &LoginPage::loginClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        switch (app) {
        case App::Car:
            showPage(ui->pageCar);
            break;
        case App::Repair:
            showPage(ui->pageRepair);
            break;
        case App::Buy:
            showPage(ui->pageBuy);
            break;
        case App::Print:
            showPage(ui->pagePrint);
            break;
        case App::Room:
            showPage(ui->pageRoom);
            break;
        case App::Asset:
            showPage(ui->pageAsset);
            break;
        default:
            break;
        }
    });

    connect(ui->pageCar, &CarPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
    //asset pages
    connect(ui->pageRepair, &RepairPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
    //asset pages
    connect(ui->pageBuy, &BuyPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
    //asset pages
    connect(ui->pagePrint, &PrintPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
    //asset pages
    connect(ui->pageRoom, &RoomPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    //asset pages
    connect(ui->pageAsset, &AssetPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageAsset, &AssetPage::inputQcClicked, [this]{
        showPage(ui->pageAssetQuery);
    });

    connect(ui->pageAssetQuery, &AssetQuery::okClicked, [this]{
        showPage(ui->pageAssetInfo);
    });

    connect(ui->pageAssetQuery, &AssetQuery::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageAssetInfo, &AssetInfo::backClicked, [this]{
        showPage(ui->pageManager);
    });
}

void MainWindow::hidePages()
{
    for(auto page : m_pageList){
        page->hide();
    }
}

void MainWindow::showPage(QWidget *page)
{
    page->show();
    page->raise();
    QTimer::singleShot(ANIMATION_DURATION, this, [this, page](){
        for(auto p : m_pageList){
            if(p != page){
                p->hide();
            }
        }
    });
}
