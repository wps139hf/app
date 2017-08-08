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

    hidePagesNoToolBar();

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

    for(auto page : m_listNoToolBarPage){
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
    m_listNoToolBarPage.append(ui->pageWelcome);
    m_listNoToolBarPage.append(ui->pageLogin);
    m_listNoToolBarPage.append(ui->pageCar);
    m_listNoToolBarPage.append(ui->pageRepair);

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
        default:
            break;
        }
    });

    connect(ui->pageCar, &CarPage::backClicked, [this]{
        showPage(ui->pageManager);
    });

    connect(ui->pageRepair, &RepairPage::backClicked, [this]{
        showPage(ui->pageManager);
    });
}

void MainWindow::hidePagesNoToolBar()
{
    for(auto page : m_listNoToolBarPage){
        page->hide();
    }
}

void MainWindow::showPage(QWidget *page)
{
    page->show();

    QTimer::singleShot(ANIMATION_DURATION, this, [this, page](){
        for(auto p : m_listNoToolBarPage){
            if(p != page){
                p->hide();
            }
        }
    });
}
