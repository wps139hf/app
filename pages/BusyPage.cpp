#include "BusyPage.h"
#include "ui_BusyPage.h"

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

BusyPage *BusyPage::instance()
{
    static BusyPage busyPage;
    return &busyPage;
}
