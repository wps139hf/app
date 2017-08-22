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

    m_notification = QSharedPointer<Notification>::create(this);

    startUp();
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

void MainWindow::setupConnections()
{
    connect(this, &MainWindow::notified, [this](const QString &notification){
        m_notification->setText(notification);
    });

    connect(ModelManager::instance(), &ModelManager::requestLaunch, [this](){
        ui->pageBusy->show();
        ui->pageBusy->raise();
        wait(50);
    });
    connect(ModelManager::instance(), &ModelManager::requestFinish, [this](){
        ui->pageBusy->hide();
    });

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
        {
            MutiRoomModel *model = ModelManager::instance()->multiRoom();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pageRoomList);
            }else{
                sendError(model->errorMsg());
            }
            break;
        }
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
    //roomList pages
    connect(ui->pageRoomList, &RoomPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
    //room pages
    connect(ui->pageRoom, &RoomPage::backClicked, [this]{
        showPage(ui->pageRoomList);
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
}

void MainWindow::startUp()
{
    ApplicationModel *app = ModelManager::instance()->application();
    if(!app->logined()){
        showPage(ui->pageWelcome);
    }else{
        showPage(ui->pageManager);
    }
}

void MainWindow::wait(int msecond)
{
    QEventLoop loop;
    QTimer::singleShot(msecond, &loop, SLOT(quit()));
    loop.exec();
}
