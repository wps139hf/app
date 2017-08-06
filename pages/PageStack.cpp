#include "PageStack.h"
#include "ui_PageStack.h"

PageStack::PageStack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageStack)
{
    ui->setupUi(this);
}

PageStack::~PageStack()
{
    delete ui;
}

void PageStack::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
}
