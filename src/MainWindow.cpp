#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->toolBar, &ToolBar::clicked, [this](int btnIndex){
        switch (btnIndex) {
        case ToolBar::Message:
            ui->pagePanel->showMsg();
            break;
        case ToolBar::Home:
            ui->pagePanel->showHome();
            break;
        case ToolBar::Mine:
            ui->pagePanel->showMine();
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

    ui->pagePanel->resize(width(), height() - ui->toolBar->height());
    ui->pagePanel->move(0, 0);

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
    ui->toolBar->raise();
}
