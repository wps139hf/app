#include "BasePage.h"
#include "ui_BasePage.h"

BasePage::BasePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BasePage)
{
    ui->setupUi(this);

    connect(ui->titleBar, SIGNAL(backClicked(bool)), this, SIGNAL(backClicked(bool)));
    connect(ui->titleBar, SIGNAL(customClicked(bool)), this, SIGNAL(customClicked(bool)));
}

BasePage::~BasePage()
{
    delete ui;
}

void BasePage::setTitle(const QString &title)
{
    ui->titleBar->setText(title);
}

void BasePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    ui->titleBar->resize(width(), ui->titleBar->height());
    ui->titleBar->move(0, 0);
}
