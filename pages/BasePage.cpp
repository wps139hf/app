#include "BasePage.h"

BasePage::BasePage(QWidget *parent) :
    QWidget(parent)
{
}

BasePage::~BasePage()
{
}

void BasePage::setTitleBar(TitleBar *bar)
{
    m_titleBar = bar;
    connect(m_titleBar, SIGNAL(backClicked(bool)), this, SIGNAL(backClicked(bool)));
    connect(m_titleBar, SIGNAL(customClicked(bool)), this, SIGNAL(customClicked(bool)));
}

void BasePage::setTitle(const QString &title)
{
    if(m_titleBar){
        m_titleBar->setText(title);
    }else{
        qWarning("No title bar to display!");
    }
}

void BasePage::showBackButton()
{
    if(m_titleBar){
        m_titleBar->setBackButtonVisible(true);
    }
}

void BasePage::showCustomButton()
{
    if(m_titleBar){
        m_titleBar->setCustomButtonVisible(true);
    }
}

void BasePage::init()
{

}

void BasePage::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    qDebug() << objectName() << "show up.";
    init();
}
