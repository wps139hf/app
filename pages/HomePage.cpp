#include "HomePage.h"
#include "ui_HomePage.h"

#include <QResizeEvent>
#include <QPainter>

HomePage::HomePage(QWidget *parent) :
    BasePage(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);

    connect(ui->appWidget, SIGNAL(clicked(int)), this, SLOT(onAppSelected(int)));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::onAppSelected(int index)
{
    qDebug() << "onAppSelected, index=" << index;
}

void HomePage::init()
{
    setTitle(tr("爱菊微后勤"));
    setTitleButtonVisible(TitleBar::Back, false);
    setTitleButtonVisible(TitleBar::Custom, false);
    setToolButtonChecked(ToolBar::Home);
}

void HomePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    BasePage::resizeEvent(e);
    ui->titleBar->resize(width(), ui->titleBar->height());
    ui->banner->resize(width(), ui->banner->height());
    ui->banner->move(0, ui->titleBar->height());

    ui->appWidget->resize(width(), ui->appWidget->height());
    ui->appWidget->move(0, height() - ui->appWidget->height());

    int h = ui->appWidget->geometry().top() - ui->banner->geometry().bottom();
    ui->notice->resize(width(), h);
    ui->notice->move(ui->banner->geometry().bottomLeft());
}

void HomePage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}
