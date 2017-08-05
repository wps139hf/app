#include "NoticeWidget.h"
#include "ui_NoticeWidget.h"

NoticeWidget::NoticeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticeWidget)
{
    ui->setupUi(this);
}

NoticeWidget::~NoticeWidget()
{
    delete ui;
}

void NoticeWidget::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    ui->title->resize(width(), ui->title->height());
    ui->title->move(rect().topLeft());
}
