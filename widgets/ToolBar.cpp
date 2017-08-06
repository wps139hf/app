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
    ui->btnMsg->setText(tr("Message"));
    ui->btnMsg->setImage(QImage("://icons/icon-msg.png"));

    ui->btnHome->setCheckable(true);
    ui->btnHome->setText(tr("Home"));
    ui->btnHome->setImage(QImage("://icons/icon-home.png"));

    ui->btnMine->setCheckable(true);
    ui->btnMine->setText(tr("Mine"));
    ui->btnMine->setImage(QImage("://icons/icon-mine.png"));

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
}

void ToolBar::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    relayout();
}

void ToolBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    painter.fillRect(rect(), Qt::lightGray);
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
