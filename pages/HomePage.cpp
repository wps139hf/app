#include "HomePage.h"
#include "ui_HomePage.h"

#include <QResizeEvent>
#include <QPainter>
#include <QDebug>

HomePage::HomePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setTitle(tr("爱菊微后勤"));

    connect(ui->appWidget, SIGNAL(clicked(int)), this, SLOT(onAppSelected(int)));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::onAppSelected(int index)
{
    qDebug() << "onAppSelected, index=" << index;
}

void HomePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    BasePage::resizeEvent(e);
    ui->appWidget->resize(width(), ui->appWidget->height());
    ui->appWidget->move(0, height() - ui->appWidget->height());
}

void HomePage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}
