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

    ui->applications->resize(width(), ui->applications->height());

    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
    ui->toolBar->raise();
}

void HomePage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}
