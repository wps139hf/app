#include "LoginPage.h"
#include "ui_LoginPage.h"

LoginPage::LoginPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->btnLogin, SIGNAL(clicked(bool)), this, SIGNAL(loginClicked()));
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::init()
{
    setTitle(tr("登录"));
    setTitleButtonVisible(TitleBar::Back, false);
    setTitleButtonVisible(TitleBar::Custom, false);
}
