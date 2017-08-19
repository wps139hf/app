#include "BusyPage.h"
#include "ui_BusyPage.h"

#include "Http.h"

BusyPage::BusyPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusyPage)
{
    ui->setupUi(this);
}

BusyPage::~BusyPage()
{
    delete ui;
}
