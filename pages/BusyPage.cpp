#include "BusyPage.h"
#include "ui_BusyPage.h"

BusyPage::BusyPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusyPage)
{
    ui->setupUi(this);

    QMovie *movie = new QMovie(":/icons/loading.gif");
    ui->gifLabel->setMovie(movie);
    movie->start();
}

BusyPage::~BusyPage()
{
    delete ui;
}

void BusyPage::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    int x = width()/2 - ui->tray->width()/2;
    int y = height()/2 - ui->tray->height()/2;
    ui->tray->move(x, y);
}
