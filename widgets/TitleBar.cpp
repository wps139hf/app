#include "TitleBar.h"
#include "ui_TitleBar.h"

#include <QPainter>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

    ui->btnBack->setVisible(false);
    ui->btnCustom->setVisible(false);

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(backClicked(bool)));
    connect(ui->btnCustom, SIGNAL(clicked(bool)), this, SIGNAL(customClicked(bool)));
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::setButtonVisible(TitleBar::Button btn, bool visible)
{
    switch (btn) {
    case TitleBar::Back:
        ui->btnBack->setVisible(visible);
        break;
    case TitleBar::Custom:
        ui->btnCustom->setVisible(visible);
        break;
    default:
        break;
    }
}

void TitleBar::setText(const QString &text)
{
    ui->title->setText(text);
}

void TitleBar::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    ui->btnBack->move(0, 0);
    ui->btnCustom->move(width() - ui->btnCustom->width(), 0);

    ui->title->resize(width(), height());
    ui->title->move(0, 0);

    ui->btnBack->raise();
    ui->btnCustom->raise();
}

void TitleBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    painter.fillRect(rect(), Qt::darkBlue);
}
