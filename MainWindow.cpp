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
    connectionsOnLogin();
    connectionsOnNotification();
    connectionsOnBusyPage();

    connectionsOnCar();
    connectionsOnRepair();
    connectionsOnBuy();
    connectionsOnPrint();
    connectionsOnRoom();
    connectionsOnAsset();
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

void MainWindow::connectionsOnLogin()
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

    connect(ui->pageManager->minePage(), &MinePage::logout, [this](){
        showPage(ui->pageWelcome);
    });
}

void MainWindow::connectionsOnNotification()
{
    connect(this, &MainWindow::notified, [this](const QString &notification){
        m_notification->setText(notification);
    });
    connect(ui->pageManager, &PageManager::notified, [this](const QString &notification){
        m_notification->setText(notification);
    });
}

void MainWindow::connectionsOnBusyPage()
{
    connect(ModelManager::instance(), &ModelManager::requestLaunch, [this](){
        ui->pageBusy->show();
        ui->pageBusy->raise();
        wait(50);
    });
    connect(ModelManager::instance(), &ModelManager::requestFinish, [this](){
        ui->pageBusy->hide();
    });
}

void MainWindow::connectionsOnCar()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Car) {
            CarModel *model = ModelManager::instance()->car();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pageCarList);
            }else{
                sendNotification(model->errorMsg());
            }
        }

    });
    connect(ui->pageCarList, &CarList::itemSelected, [this]{
        showPage(ui->pageCar);
    });

    connect(ui->pageCarList, &CarList::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageCar, &CarPage::backClicked, [this]{
        showPage(ui->pageCarList);
    });
}

void MainWindow::connectionsOnRepair()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Repair){
            RepairModel *model = ModelManager::instance()->repair();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pageRepairList);
            }else{
                sendNotification(model->errorMsg());
            }
        }
    });

    connect(ui->pageRepair, &RepairPage::backClicked, [this]{
        showPage(ui->pageRepairList);
    });

    connect(ui->pageRepairList, &RepairPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageRepairList, &RepairList::itemSelected, [this]{
        showPage(ui->pageRepair);
    });
}

void MainWindow::connectionsOnBuy()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Buy){
            BuyModel *model = ModelManager::instance()->buy();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pageBuyList);
            }else{
                sendNotification(model->errorMsg());
            }
        }
    });

    connect(ui->pageBuy, &BuyPage::backClicked, [this]{
        showPage(ui->pageBuyList);
    });

    connect(ui->pageBuyList, &BuyPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageBuyList, &BuyList::itemSelected, [this]{
        showPage(ui->pageBuy);
    });
}

void MainWindow::connectionsOnPrint()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Print){
            PrintModel *model = ModelManager::instance()->print();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pagePrintList);
            }else{
                sendNotification(model->errorMsg());
            }
        }
    });

    connect(ui->pagePrint, &PrintPage::backClicked, [this]{
        showPage(ui->pagePrintList);
    });

    connect(ui->pagePrintList, &PrintPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pagePrintList, &PrintList::itemSelected, [this]{
        showPage(ui->pagePrint);
    });

    connect(ui->pagePrintList, &PrintList::request, [this]{
        showPage(ui->pagePrintRequest);
    });

    connect(ui->pagePrintRequest, &PrintRequest::backClicked, [this]{
        showPage(ui->pagePrintList);
    });
}

void MainWindow::connectionsOnRoom()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Room){
            MutiRoomModel *model = ModelManager::instance()->multiRoom();
            model->request();
            if(model->errorMsg().isNull() || model->errorMsg().isEmpty()){
                showPage(ui->pageRoomList);
            }else{
                sendNotification(model->errorMsg());
            }
        }
    });

    connect(ui->pageRoomList, &RoomList::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageRoomList, &RoomList::itemSelected, [this]{
        showPage(ui->pageRoom);
    });

    connect(ui->pageRoom, &RoomPage::backClicked, [this]{
        showPage(ui->pageRoomList);
    });
}

void MainWindow::connectionsOnAsset()
{
    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        if(app == App::Asset){
            showPage(ui->pageAssetScan);
        }
    });

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
