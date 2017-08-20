#include "MessagePage.h"
#include "ui_MessagePage.h"

MessagePage::MessagePage(QWidget *parent)
    : BasePage(parent)
    , ui(new Ui::MessagePage)
{
    ui->setupUi(this);
    setTitleBar(ui->titleBar);

    ui->titleBar_2->move(0,0);
    ui->titleBar_2->setButtonVisible(TitleBar::Back,true);
    ui->titleBar_2->setText(tr("消息详情"));
    ui->titleBar_2->hide();

    QStringList content;
    content<< "  This is message One" << "  This is message Two" << "  This is message Three"
           << "  This is message Four" << "  This is message Five" << "  This is message Six"
           << "  This is message Seven" << "  This is message Eight" << "  This is message Nine"
           << "  This is message Ten" << "  This is message Eleven" << "  This is message Twelve"
           << "  This is message Thirteen";

    m_pMessageList = new MessageList(content,this);

    m_pMessageList->move(0,44);

    m_pMessageTime = new QLabel(this);
    m_pMessageTime -> move(MESSAGE_WID_TIME_X,MESSAGE_WID_TIME_Y);
    m_pMessageTime -> resize(MESSAGE_WID_TIME_WIDTH,MESSAGE_WID_TIME_HEIGHT);
    m_pMessageTime -> setText("");
    m_pMessageTime -> setAlignment(Qt::AlignVCenter);
    m_pMessageTime -> hide();

    m_pMessageText = new QLabel(this);
    m_pMessageText -> move(MESSAGE_WID_TEXT_X,MESSAGE_WID_TEXT_Y);
    m_pMessageText -> resize(MESSAGE_WID_TEXT_WIDTH,MESSAGE_WID_TEXT_HEIGHT);
    m_pMessageText -> setText("");
    m_pMessageText -> setStyleSheet("background-color:rgb(200,200,200)");//背景色
    m_pMessageText -> hide();

    connect(m_pMessageList,SIGNAL(messageClicked(QString , QString)),this,SLOT(setMessageContent(QString , QString)));
    connect(ui->titleBar_2,SIGNAL(backClicked(bool)),this,SLOT(slotBacktoList(bool)));
}

MessagePage::~MessagePage()
{
    delete ui;
}

void MessagePage::init()
{
    setTitle(tr("消息"));
    setTitleButtonVisible(TitleBar::Back, true);
    setTitleButtonVisible(TitleBar::Custom, false);
    setToolButtonChecked(ToolBar::Message);
}

void MessagePage::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    BasePage::resizeEvent(e);

    m_pMessageList->resize(width(),height());
    //m_pMessageWid->resize(width(),height());
}

void MessagePage::setMessageContent(QString time, QString content)
{
    qDebug()<<"MessagePage::setMessageContent"<<time<<content;
    m_pMessageTime -> setText(time);
    m_pMessageText -> setText(content);
    m_pMessageList->hide();
    m_pMessageTime -> show();
    m_pMessageText -> show();
    ui->titleBar->hide();
    ui->titleBar_2->show();
}

void MessagePage::slotBacktoList(bool flag)
{
    qDebug()<<"MessagePage::slotBacktoList";
    m_pMessageList->show();
    m_pMessageTime -> hide();
    m_pMessageText -> hide();
    ui->titleBar->show();
    ui->titleBar_2->hide();
}


int gMessageNum=0;

MessageList::MessageList(const QStringList &content, QWidget *parent)
    : QWidget(parent)
{
    gMessageNum = content.size();
    QDateTime time = QDateTime::currentDateTime();

    m_pList = new QListWidget(this);
    m_pList->move(0,0);
    m_pList->setWindowFlags(Qt::FramelessWindowHint);
    m_pList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //m_pList->resize(WINDOW_WIDTH,MESSAGE_BOX_HEIGHT*gMessageNum);

    for(int i=0;i<gMessageNum;i++)
    {
        MessageBox *messageBox = new MessageBox(time,m_pList,content.at(i));
        message_array.append(messageBox);

        QListWidgetItem* pItem = new QListWidgetItem(m_pList);
        m_pList->setItemWidget(pItem,messageBox);
        connect(messageBox,SIGNAL(messageBoxClicked(QString,QString)),this,SIGNAL(messageClicked(QString,QString)));
    }
}

MessageList::~MessageList()
{

}

void MessageList::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    m_pList->resize(width(),height()*0.06*gMessageNum);
    for(int i=0;i<gMessageNum;i++)
    {
        m_pList->item(i)->setSizeHint(QSize(width(),height()*0.06));
    }
}

MessageBox::MessageBox(const QDateTime &time, QWidget *parent, QString message)
    : QWidget(parent)
    , label_move(true)
    , m_sContent(message)
{
    m_sTime = time.toString("hh:mm");

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    resize(MESSAGE_BOX_WIDTH, MESSAGE_BOX_HEIGHT);

    m_pMessageIcon = new QLabel(this);
    m_pMessageIcon->setStyleSheet("background:green");

    m_pMessageText = new QLabel(this);
    m_pMessageText->setText(m_sContent);

    m_pMessageTime= new QLabel(this);
    m_pMessageTime->setText(m_sTime);
}

MessageBox::~MessageBox()
{

}

void MessageBox::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    m_pMessageIcon->resize(parentWidget()->width()*0.2,parentWidget()->height()*0.03);
    m_pMessageIcon->move(0,0);

    m_pMessageText->resize(parentWidget()->width()*0.6,parentWidget()->height()*0.03);
    m_pMessageText->move(parentWidget()->width()*0.2,0);

    m_pMessageTime->resize(parentWidget()->width()*0.2,parentWidget()->height()*0.03);
    m_pMessageTime->move(parentWidget()->width()*0.8,0);
}

void MessageBox::mousePressEvent(QMouseEvent *event)
{
    m_mouseSrcPos = event->pos();
    QListWidget *temp = (QListWidget*)parentWidget();
    current_pos_y = temp->y();
    mouse_press = true;
}

void MessageBox::mouseReleaseEvent(QMouseEvent *event)
{
    int ypos = 0;
    if (mouse_press) {
        if (label_move) {
            QListWidget *temp = (QListWidget*)parentWidget();
            ypos = temp->y();
            if(ypos>0)
                temp->move(temp->x() ,0);
            else if(ypos<(WINDOW_HEIGHT-gMessageNum*MESSAGE_BOX_HEIGHT))
                temp->move(temp->x(),WINDOW_HEIGHT-gMessageNum*MESSAGE_BOX_HEIGHT);
        }
        mouse_press = false;
    }
    m_mouseDstPos = event->pos();
    if(m_mouseDstPos.y()-m_mouseSrcPos.y()>-10 && m_mouseDstPos.y()-m_mouseSrcPos.y()<10 )
    {
        qDebug("Am i Here?");
        emit messageBoxClicked(m_sTime,m_sContent);
    }
    qDebug("MessageBox::mouseReleaseEvent");
}

void MessageBox::mouseMoveEvent(QMouseEvent *event)
{
    int yPos = 0;
    if(mouse_press) {
        if(label_move) {
            m_mouseDstPos = event->pos();
            yPos = m_mouseDstPos.y() - m_mouseSrcPos.y();

            setLabelMove(false);
            QListWidget *temp = (QListWidget*)parentWidget();
            temp->move(0,current_pos_y + yPos);
            setLabelMove(true);
        }
    }
    qDebug("MessageBox::mouseMoveEvent");
}

void MessageBox::setLabelMove(bool enable)
{
    label_move = enable;
}
