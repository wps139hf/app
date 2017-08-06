#include "WelcomePage.h"
#include "ui_WelcomePage.h"

#include <QDebug>

WelcomePage::WelcomePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    qDebug() << "WelcomePage::resizeEvent," << e;
}
