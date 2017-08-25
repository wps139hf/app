#include "ToolBar.h"
#include "ui_ToolBar.h"

#include <QResizeEvent>
#include <QPainter>
#include <QTimer>
#include <QDebug>

ToolBar::ToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBar)
{
    ui->setupUi(this);

    ui->btnMsg->setCheckable(true);
    ui->btnMsg->setText(tr("消息"));
    ui->btnMsg->setPixmap(QPixmap("://icons/icon-msg-unselected.jpg"));
    ui->btnMsg->setMsgCount(10);

    ui->btnHome->setCheckable(true);
    ui->btnHome->setText(tr("主页"));
    ui->btnHome->setPixmap(QPixmap("://icons/icon-home-unselected.jpg"));

    ui->btnMine->setCheckable(true);
    ui->btnMine->setText(tr("我的"));
    ui->btnMine->setPixmap(QPixmap("://icons/icon-mine-unselected.jpg"));

    m_btnGrp = new QButtonGroup(this);
    m_btnGrp->addButton(ui->btnMsg, ToolBar::Message);
    m_btnGrp->addButton(ui->btnHome, ToolBar::Home);
    m_btnGrp->addButton(ui->btnMine, ToolBar::Mine);
    m_btnGrp->setExclusive(true);

    connect(m_btnGrp, SIGNAL(buttonClicked(int)), this, SIGNAL(clicked(int)));

    //show default page - home page
    QTimer::singleShot(50, this, [this](){
        qDebug() << "show default page";
//        emit m_btnGrp->buttonClicked(ToolBar::Home);
//        ui->btnHome->click();
        setChecked(ToolBar::Home);
    });
}

ToolBar::~ToolBar()
{
    delete ui;
}

void ToolBar::setChecked(int btnIndex)
{
//    emit clicked(btnIndex);
    m_btnGrp->button(btnIndex)->click();
    if(btnIndex == ToolBar::Message)
    {
        ui->btnMsg->setPixmap(QPixmap("://icons/icon-msg.png"));
        ui->btnHome->setPixmap(QPixmap("://icons/icon-home-unselected.jpg"));
        ui->btnMine->setPixmap(QPixmap("://icons/icon-mine-unselected.jpg"));
    }
    else if(btnIndex == ToolBar::Home)
    {
        ui->btnMsg->setPixmap(QPixmap("://icons/icon-msg-unselected.jpg"));
        ui->btnHome->setPixmap(QPixmap("://icons/icon-home.png"));
        ui->btnMine->setPixmap(QPixmap("://icons/icon-mine-unselected.jpg"));
    }
    else if(btnIndex == ToolBar::Mine)
    {
        ui->btnMsg->setPixmap(QPixmap("://icons/icon-msg-unselected.jpg"));
        ui->btnHome->setPixmap(QPixmap("://icons/icon-home-unselected.jpg"));
        ui->btnMine->setPixmap(QPixmap("://icons/icon-mine.png"));
    }
}

//void ToolBar::resizeEvent(QResizeEvent *e)
//{
//    Q_UNUSED(e);
////    relayout();
//}

void ToolBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    painter.setPen(QColor(220, 220, 220));
    painter.drawLine(0,0,width(),0);
}

void ToolBar::relayout()
{
    QList<QAbstractButton*>list = m_btnGrp->buttons();
    if(list.size()){
        int step = width() / list.size();
        QSize btnSize = QSize(height(), height());
        int margin = step/2 - btnSize.width()/2;
        int start = rect().left();

        for(auto btn : list){
            btn->setFixedSize(btnSize);
            btn->move(start + margin, 0);
            start += step;
        }
    }
}
