#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainPages->setTitleBar(ui->titleBar);
    ui->mainPages->setToolBar(ui->toolBar);

    connect(ui->toolBar, &ToolBar::clicked, [this](int btnIndex){
        qDebug() << "toolbar: clicked:" << btnIndex;
        switch (btnIndex) {
        case ToolBar::Message:
            ui->mainPages->showMsg();
            break;
        case ToolBar::Home:
            ui->mainPages->showHome();
            break;
        case ToolBar::Mine:
            ui->mainPages->showMine();
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
    ui->mainPages->resize(width(), h);
    ui->mainPages->move(0, 0);

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
    ui->toolBar->raise();
}
