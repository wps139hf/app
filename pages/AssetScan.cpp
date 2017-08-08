#include "AssetScan.h"
#include "ui_AssetScan.h"

#include <QPainter>

AssetScan::AssetScan(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetScan)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);

    setBackgroundColor(Qt::black);

    connect(ui->btnInputQc, SIGNAL(clicked(bool)), this, SIGNAL(inputQcClicked()));
}

AssetScan::~AssetScan()
{
    delete ui;
}

void AssetScan::init()
{
    setTitle(tr("扫一扫"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
