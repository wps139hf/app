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
    ui->gifLabel->move(0.5*width()-0.5*ui->gifLabel->width(),0.25*height());
    ui->textLabel->move(0.5*width()-0.5*ui->textLabel->width(),0.75*height());
}
