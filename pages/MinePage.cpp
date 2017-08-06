#include "MinePage.h"
#include "ui_MinePage.h"

MinePage::MinePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::MinePage)
{
    ui->setupUi(this);
}

MinePage::~MinePage()
{
    delete ui;
}

void MinePage::showEvent(QShowEvent *e)
{
    BasePage::showEvent(e);
    setTitle(tr("我的信息"));
    qDebug() << objectName() << "show up.";
}
