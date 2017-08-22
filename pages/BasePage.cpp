#include "BasePage.h"

#include <QPainter>
#include <QTimer>

BasePage::BasePage(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundColor(Qt::white);
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

void BasePage::setToolBar(ToolBar *bar)
{
    m_toolbar = bar;
}

void BasePage::setTitle(const QString &title)
{
    if(m_titleBar){
        m_titleBar->setText(title);
    }else{
        qDebug() << " !!! No title bar for page " << objectName() << ".!!!";
    }
}

void BasePage::setTitleButtonVisible(TitleBar::Button btn, bool visible)
{
    if(m_titleBar){
        m_titleBar->setButtonVisible(btn, visible);
    }else{
        qDebug() << " !!! No title bar for page " << objectName() << ".!!!";
    }
}

void BasePage::setToolButtonChecked(ToolBar::Button btn)
{
    if(m_toolbar){
        m_toolbar->setChecked(btn);
    }else{
        qDebug() << " !!! No toolbar for page " << objectName() << ".!!!";
    }
}

void BasePage::setBackgroundColor(const QColor &color)
{
    m_backgoundColor = color;
    update();
}

void BasePage::sendNotification(const QString &notification)
{
    emit notified(notification);
}

void BasePage::init()
{
}

void BasePage::refresh()
{

}

void BasePage::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    raise();
    qDebug() << objectName() << "show up.";
    init();

    refresh();
}

void BasePage::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.fillRect(rect(), m_backgoundColor);
}

