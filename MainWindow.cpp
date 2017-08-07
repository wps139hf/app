#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QKeyEvent>

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
        ui->pageManager->hide();
        ui->pageWelcome->show();
    }else{
        ui->pageManager->show();
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
        ui->pageLogin->hide();
        ui->pageManager->show();
    });

    connect(ui->pageManager->homePage(), &HomePage::appSelected, [this](int app){
        switch (app) {
        case App::Car:
            ui->pageCar->show();
            break;
        default:
            break;
        }
    });

    connect(ui->pageCar, &CarPage::backClicked, [this]{
        ui->pageCar->hide();
        ui->pageManager->show();
    });
}

void MainWindow::hidePagesNoToolBar()
{
    for(auto page : m_listNoToolBarPage){
        page->hide();
    }
}

void MainWindow::showPage(BasePage *page)
{
    for(auto p : m_listNoToolBarPage){
        if(p == page){
            p->show();
        }else{
            p->hide();
        }
    }
}
