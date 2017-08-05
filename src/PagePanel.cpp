#include "PagePanel.h"
#include "ui_PagePanel.h"

PagePanel::PagePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PagePanel)
{
    ui->setupUi(this);
}

PagePanel::~PagePanel()
{
    delete ui;
}

void PagePanel::showMsg()
{
    ui->pageMsg->show();
    ui->pageMsg->raise();
}

void PagePanel::showHome()
{
    ui->pageHome->show();
    ui->pageHome->raise();
}

void PagePanel::showMine()
{
    ui->pageMine->show();
    ui->pageMine->raise();
}
