#include "NoticeWidget.h"
#include "ui_NoticeWidget.h"
#include "AbbrNoticeItem.h"
#include "NoticeDisplay.h"

#include <QDebug>

NoticeWidget::NoticeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticeWidget)
{
    ui->setupUi(this);

    ui->listWidget->addItem(new AbbrNoticeItem(tr("0张小名荣获第二届少年文艺大赛二等奖....")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("1我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("2我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("3张小名荣获第二届少年文艺大赛二等奖....")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("4我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("5我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("6我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("7我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("8我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("9我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("10我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("11我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("12我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("13我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("14我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("15我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("16我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("17我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("18我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("19我校近期讲举行新生接待会.......")));
    ui->listWidget->addItem(new AbbrNoticeItem(tr("20我校近期讲举行新生接待会.......")));

    int i = 0;
    m_timer.setInterval(2000);
    connect(&m_timer, &QTimer::timeout, [this, &i](){
        qDebug() << objectName() << " is scrolling.";
        i = (i + itemCountOnePage())%ui->listWidget->count();
        QListWidgetItem *item = ui->listWidget->item(i);
        ui->listWidget->scrollToItem(item);
    });
    m_timer.start();

    connect(ui->listWidget, &QListWidget::itemClicked, [this](QListWidgetItem *item){
        qDebug() << item->text();

        NoticeDisplay *noticeDisplay = new NoticeDisplay(this);
        noticeDisplay->show();
    });
}

NoticeWidget::~NoticeWidget()
{
    delete ui;
}

void NoticeWidget::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    ui->title->resize(width(), ui->title->height());
    ui->title->move(rect().topLeft());

    ui->listWidget->resize(width(), height() - ui->title->height());
    ui->listWidget->move(ui->title->geometry().bottomLeft());
}

void NoticeWidget::mousePressEvent(QMouseEvent *e)

{
    m_timer.stop();
    QWidget::mousePressEvent(e);
}

void NoticeWidget::mouseReleaseEvent(QMouseEvent *e)
{
    m_timer.start();
    QWidget::mouseReleaseEvent(e);
}

void NoticeWidget::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    m_timer.start();
}

void NoticeWidget::hideEvent(QHideEvent *e)
{
    QWidget::hideEvent(e);
    m_timer.stop();
}

int NoticeWidget::itemHeight()
{
    QRect rc = ui->listWidget->visualItemRect(ui->listWidget->item(0));
    return rc.height();
}

int NoticeWidget::itemCountOnePage()
{
    return ui->listWidget->height() / itemHeight();
}
