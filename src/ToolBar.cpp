#include "ToolBar.h"
#include "ui_ToolBar.h"

#include <QResizeEvent>

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
    m_btnGrp->addButton(ui->btnMsg);
    m_btnGrp->addButton(ui->btnHome);
    m_btnGrp->addButton(ui->btnMine);
    m_btnGrp->setExclusive(true);
}

ToolBar::~ToolBar()
{
    delete ui;
}

void ToolBar::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
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
