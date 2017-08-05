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
