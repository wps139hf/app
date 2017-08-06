#include "NoticeDisplay.h"
#include "ui_NoticeDisplay.h"

NoticeDisplay::NoticeDisplay(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::NoticeDisplay)
{
    ui->setupUi(this);
}

NoticeDisplay::~NoticeDisplay()
{
    delete ui;
}
