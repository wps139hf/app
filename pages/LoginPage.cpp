#include "LoginPage.h"
#include "ui_LoginPage.h"
#include "ApplicationModel.h"
#include "ModelManager.h"
#include "BusyPage.h"

LoginPage::LoginPage(QWidget *parent) :
    AnimatedPage(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    setTitleBar(ui->titleBar);
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
    ApplicationModel *model = ModelManager::instance()->application();
    model->setUser(ui->username->currentText());
    model->setPassword(ui->password->text());
    model->request();

    if(model->valid()){
        model->setLogin(true);
        qDebug() << "emit logined";
        emit logined();
    }else{
        qDebug() << model->errorMsg();
    }
}

void LoginPage::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->password->setEchoMode(QLineEdit::Normal);
    }else{
        ui->password->setEchoMode(QLineEdit::Password);
    }
}
