#include "HomePage.h"
#include "ui_HomePage.h"

#include <QResizeEvent>

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
    ui->toolBar->resize(width(), ui->toolBar->height());
    ui->toolBar->move(0, height() - ui->toolBar->height());
}
