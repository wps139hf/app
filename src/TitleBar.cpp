#include "TitleBar.h"
#include "ui_TitleBar.h"

#include <QPainter>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    ui->btnBack->setImage(QImage("://icons/icon-back.png"));
    ui->btnCustom->setImage(QImage("://icons/icon-qr.png"));
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::setBackVisible(bool visible)
{

}

void TitleBar::setCustomVisible(bool visible)
{

}

void TitleBar::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->btnBack->resize(height(), height());
    ui->btnBack->move(0, 0);

    ui->title->resize(width() - 2*height(), height());
    ui->title->move(ui->btnBack->width(), 0);

    ui->btnCustom->resize(height(), height());
    ui->btnCustom->move(width() - ui->btnCustom->width(), 0);
}

void TitleBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    painter.fillRect(rect(), Qt::darkBlue);
}
