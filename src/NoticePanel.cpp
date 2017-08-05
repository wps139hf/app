#include "NoticePanel.h"
#include "ui_NoticePanel.h"

NoticePanel::NoticePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticePanel)
{
    ui->setupUi(this);
}

NoticePanel::~NoticePanel()
{
    delete ui;
}
