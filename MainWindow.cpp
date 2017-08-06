#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pageManager->setTitleBar(ui->titleBar);
    ui->pageManager->setToolBar(ui->toolBar);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    ui->titleBar->resize(width(), ui->titleBar->height());
    ui->titleBar->move(0, 0);

    int h = height() - ui->titleBar->height() - ui->toolBar->height();
    ui->pageManager->resize(width(), h);
    ui->pageManager->move(0, 0);

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
    ui->toolBar->raise();

    ui->pageStack->resize(width(), height());
    ui->pageStack->move(0, 0);
}
