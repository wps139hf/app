#include "AppWidget.h"
#include "ui_AppWidget.h"

#include <QPainter>

AppWidget::AppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppWidget)
{
    ui->setupUi(this);

    ui->btnCar->setText(tr("Use Car"));
    ui->btnCar->setImage(QImage("://icons/icon-car.png"));

    ui->btnRepair->setText(tr("Repair"));
    ui->btnRepair->setImage(QImage("://icons/icon-repair.png"));

    ui->btnBuy->setText(tr("Buy"));
    ui->btnBuy->setImage(QImage("://icons/icon-buy.png"));

    ui->btnPrint->setText(tr("Print"));
    ui->btnPrint->setImage(QImage("://icons/icon-print.png"));

    ui->btnHall->setText(tr("Hall"));
    ui->btnHall->setImage(QImage("://icons/icon-hall.png"));

    ui->btnAsset->setText(tr("Asset"));
    ui->btnAsset->setImage(QImage("://icons/icon-asset.png"));

    m_btnGrp = new QButtonGroup(this);
    m_btnGrp->addButton(ui->btnCar);
    m_btnGrp->addButton(ui->btnRepair);
    m_btnGrp->addButton(ui->btnBuy);
    m_btnGrp->addButton(ui->btnPrint);
    m_btnGrp->addButton(ui->btnHall);
    m_btnGrp->addButton(ui->btnAsset);
}

AppWidget::~AppWidget()
{
    delete ui;
}

void AppWidget::setColumn(int count)
{
    m_column = count;
}

void AppWidget::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    relayout();
}

void AppWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}

void AppWidget::relayout()
{
    QList<QAbstractButton*>list = m_btnGrp->buttons();
    ui->title->move(rect().topLeft());
    if(list.size()){
        m_row = list.size()/m_column + 1;
        int step = width()/m_column;
        QSize btnSize;
        if(ui->btnCar->width() * m_column > width()){
            btnSize = QSize(step, step);
        }else{
            btnSize = ui->btnCar->size();
        }
        int margin = step/2 - btnSize.width()/2;
        int startX = rect().left();
        int startY = rect().top() + ui->title->height();
        int count = 0;

        for(auto btn : list){
            btn->setFixedSize(btnSize);
            btn->move(startX + margin, startY + margin);
            startX += step;
            if(++count >= m_column){
                count = 0;
                startX = rect().left();
                startY += step;
            }
        }
    }
}
