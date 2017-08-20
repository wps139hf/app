#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Http.h"
#include "ModelManager.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    AbstractPageManager(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initilize();

    ApplicationModel *app = ModelManager::instance()->application();
    if(!app->logined()){
        showPage(ui->pageWelcome);
    }else{
        showPage(ui->pageManager);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::instance()
{
    static MainWindow mainWindow;
    return &mainWindow;
}

QWidget *MainWindow::busyPage()
{
    return ui->pageBusy;
}

void MainWindow::setupConnections()
{
    connect(ui->pageWelcome, &WelcomePage::loginClicked, [this]{
        showPage(ui->pageLogin);
    });

    connect(ui->pageLogin, &LoginPage::backClicked, [this]{
        showPage(ui->pageWelcome);
    });

    connect(ui->pageLogin, &LoginPage::logined, [this]{
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
            showPage(ui->pageAssetScan);
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
    connect(ui->pageAssetScan, &AssetScan::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageAssetScan, &AssetScan::inputQcClicked, [this]{
        showPage(ui->pageAssetQuery);
    });

    connect(ui->pageAssetQuery, &AssetQuery::showInfo, [this]{
        showPage(ui->pageAssetInfo);
    });

    connect(ui->pageAssetQuery, &AssetQuery::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageAssetInfo, &AssetInfo::backClicked, [this]{
        showPage(ui->pageManager);
    });
/*
    connect(ModelManager::instance(), &ModelManager::requestLaunch, [this](){
        ui->pageBusy->raise();
        ui->pageBusy->show();
//        showPage(ui->pageBusy);
        qDebug() << "Busy Page show up.";
    });
    connect(ModelManager::instance(), &ModelManager::requestFinish, [this](){
        ui->pageBusy->hide();
//        showPrevPage();
        qDebug() << "Busy Page hide.";
    });
*/
}
