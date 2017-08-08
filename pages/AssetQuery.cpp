#include "AssetQuery.h"
#include "ui_AssetQuery.h"

AssetQuery::AssetQuery(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::AssetQuery)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);

    connect(ui->btnOk, SIGNAL(clicked(bool)), this, SIGNAL(okClicked()));
}

AssetQuery::~AssetQuery()
{
    delete ui;
}

void AssetQuery::init()
{
    setTitle(tr("资产查询"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}
