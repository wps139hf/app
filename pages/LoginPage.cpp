#include "LoginPage.h"
#include "ui_LoginPage.h"
#include "ApplicationModel.h"
#include "ModelManager.h"
#include "BusyPage.h"
#include "MainWindow.h"

LoginPage::LoginPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);

    ApplicationModel *app = ModelManager::instance()->application();
    connect(app, &ApplicationModel::requestFinish, [this, app](){
        hideBusyPage();

        if(app->valid()){
            app->setLogin(true);
            qDebug() << "emit logined";
            emit logined();
        }else{
            qDebug() << "Please check username and password.";
        }
    });
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
    showBusyPage();

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
