#include "PrintRequest.h"
#include "ui_PrintRequest.h"

PrintRequest::PrintRequest(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::PrintRequest)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

PrintRequest::~PrintRequest()
{
    delete ui;
}

void PrintRequest::init()
{
    setTitle(tr("文印申请单"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
