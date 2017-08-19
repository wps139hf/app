#include "LoginPage.h"
#include "ui_LoginPage.h"
#include "ApplicationModel.h"
#include "ModelManager.h"

LoginPage::LoginPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);

    connect(ui->btnLogin, SIGNAL(clicked(bool)), this, SIGNAL(loginClicked()));
}

LoginPage::~LoginPage()
{
    delete ui;
}
void LoginPage::init()
{
    setTitle(tr("登录"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
}

void LoginPage::on_btnLogin_clicked()
{
    ApplicationModel *app = ModelManager::instance()->application();
    app->setUser(ui->username->currentText());
    app->setPassword(ui->password->text());
    app->commit();
}

void LoginPage::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->password->setEchoMode(QLineEdit::Normal);
    }else{
        ui->password->setEchoMode(QLineEdit::Password);
    }
}
