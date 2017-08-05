#include "TitleBar.h"
#include "ui_TitleBar.h"

#include <QPainter>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->btnBack->move(0, 0);
    ui->btnCustom->move(width() - ui->btnCustom->width(), 0);

    ui->title->resize(width(), height());
    ui->title->move(0, 0);

    ui->btnBack->raise();
    ui->btnCustom->raise();
}

void TitleBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    painter.fillRect(rect(), Qt::darkBlue);
}
