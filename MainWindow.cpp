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
    initToolBar();
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

    ui->pageManager->resize(width(), height() - ui->toolBar->height());
    ui->pageManager->move(0, 0);

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
    ui->toolBar->raise();

    for(auto page : m_pageList){
        page->resize(size());
        page->move(0, 0);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()){
    case Qt::Key_Up:
        qDebug() << "up key pressed.";
        ui->pageLogin->show();
        break;
    case Qt::Key_Down:
        qDebug() << "down key pressed.";
        ui->pageLogin->hide();
        break;
    default:break;
    }
}

void MainWindow::initPageList()
{
    m_pageList.append(ui->pageWelcome);
    m_pageList.append(ui->pageLogin);

    m_pageList.append(ui->pageCar);
    m_pageList.append(ui->pageRepair);
    m_pageList.append(ui->pageBuy);
    m_pageList.append(ui->pagePrint);
    m_pageList.append(ui->pageRoom);
    m_pageList.append(ui->pageAsset);
}

void MainWindow::initToolBar()
{
    ui->pageManager->setToolBar(ui->toolBar);
}

void MainWindow::initConnections()
{
    connect(ui->toolBar, &ToolBar::clicked, [this](int btnIndex){
        qDebug() << "toolbar: clicked:" << btnIndex;
        switch (btnIndex) {
        case ToolBar::Message:
            ui->pageManager->showMsg();
            break;
        case ToolBar::Home:
            ui->pageManager->showHome();
            break;
        case ToolBar::Mine:
            ui->pageManager->showMine();
            break;
        default:
            break;
        }
    });

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

    connect(ui->pageCar, &BasePage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageRepair, &BasePage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageBuy, &BasePage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pagePrint, &BasePage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageRoom, &BasePage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageAsset, &BasePage::backClicked, [this]{
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
