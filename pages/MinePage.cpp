#include "MinePage.h"
#include "ui_MinePage.h"
#include "ModelManager.h"

MinePage::MinePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::MinePage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);
}

MinePage::~MinePage()
{
    delete ui;
}

void MinePage::init()
{
    setTitle(tr("我的信息"));
    setTitleButtonVisible(TitleBar::Back, false);
    setTitleButtonVisible(TitleBar::Custom, false);
    setToolButtonChecked(ToolBar::Mine);
}

void MinePage::on_btnLogout_clicked()
{
    ApplicationModel *app = ModelManager::instance()->application();
    app->setLogin(false);
    emit logout();
}
