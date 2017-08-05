#include "MainPages.h"
#include "ui_MainPages.h"

MainPages::MainPages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPages)
{
    ui->setupUi(this);
}

MainPages::~MainPages()
{
    delete ui;
}

void MainPages::showMsg()
{
    ui->pageMsg->show();
    ui->pageMsg->raise();
}

void MainPages::showHome()
{
    ui->pageHome->show();
    ui->pageHome->raise();
}

void MainPages::showMine()
{
    ui->pageMine->show();
    ui->pageMine->raise();
}
