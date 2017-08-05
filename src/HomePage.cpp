#include "HomePage.h"
#include "ui_HomePage.h"

#include <QResizeEvent>
#include <QPainter>

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->titleBar->resize(width(), ui->titleBar->height());
    ui->titleBar->move(0, 0);

    ui->appPanel->resize(width(), ui->appPanel->height());
    ui->appPanel->move(0, height() - ui->appPanel->height());
}

void HomePage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}
