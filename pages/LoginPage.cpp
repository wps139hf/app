#include "LoginPage.h"
#include "ui_LoginPage.h"

#include "Http.h"

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
    QAuthenticator auth;
    auth.setUser("sa");
    auth.setPassword("123");
    Http::instance().setAuthenticator(auth);

//    Http::instance().startRequest(QUrl("https://passport.jd.com/new/login.aspx?ReturnUrl=https%3A%2F%2Fsearch.jd.com%2FSearch%3Fkeyword%3Dmac%2520mini%26enc%3Dutf-8%26wq%3Dmac%2520mini%26pvid%3D2034e5a06e35487fba1f3ef6aff1aab6"));
//    Http::instance().startRequest(QUrl("http://180.153.158.111:89/app/assets.asmx"));
    Http::instance().startRequest(QUrl("http://180.153.158.111:89/app/assets.asmx?op=GetAsset"));
}

void LoginPage::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->password->setEchoMode(QLineEdit::Normal);
    }else{
        ui->password->setEchoMode(QLineEdit::Password);
    }
}
