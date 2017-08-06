#include "sliderpicture.h"

SliderPicture::SliderPicture(QWidget *parent)
    : QWidget(parent)
    , mouse_press(false)
//    , mouse_move(false)
    , label_move(true)
    , current_index(0)
    , current_pos_x(0)
    , strSelected("QLabel{background:rgb(150,150,150);}")
    , strUnselected("QLabel{background:rgb(255,255,255);}")
{
//    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    resize(680, 370);

    background_label = new QLabel(this);
    background_label->setPixmap(QPixmap(":/bg_bottom"));
    background_label->setGeometry(QRect(0, 0, this->width(), this->height()));

    QPixmap pixmap(QSize(this->width()*4, this->height()));
    QPainter painter(&pixmap);
    for(int i = 0; i < 4; i++){
        painter.drawImage(QRect(this->width()*i, 0, this->width(), this->height()),
                          QImage(QString(":/desktop_%1").arg(i)));
    }
    total_label = new QLabel(this);
    total_label->resize(pixmap.size());
    total_label->setPixmap(pixmap);
    total_label->move(0, 0);

    for(int index = 0; index < 4; index++) {
        QLabel *label = new QLabel(this);
        label->resize(QSize(15, 15));
        label->move(298+index*23, 319);
        label->setStyleSheet(strUnselected);
        label_array.append(label);
    }
    label_array.first()->setFocus();
    label_array.first()->setStyleSheet(strSelected);
}

SliderPicture::~SliderPicture()
{

}

void SliderPicture::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        m_mouseSrcPos = event->pos();
//        if(m_mouseSrcPos.y() <= 40) {
//            mouse_move = true;
//        }
//        else
        {
            current_pos_x = total_label->x();
            mouse_press = true;
        }
    }
    else if(event->button() == Qt::RightButton) {
        if(label_move) {
            if(current_index > 0) {
                current_index--;
                moveCurrentPage(false);  //move right
            }
        }
    }
}

void SliderPicture::mouseReleaseEvent(QMouseEvent *event)
{
    int xpos = 0;
    if (mouse_press) {
        if (label_move) {
            m_mouseDstPos = event->pos();
            xpos = m_mouseDstPos.x() - m_mouseSrcPos.x();
            if (xpos > 0) {                     //the plan is:move right
                if(xpos >= 150) {               //mouse gap
                    if(current_index > 0) {     //move right
                        current_index--;
                        moveCurrentPage(false);
                    }
                    else {
                        moveCurrentPage(true);  //move left
                    }
                }
                else {
                     moveCurrentPage(true);     //move left
                }
            }
            else {             //the plan is:move right
                if(xpos <= -150)
                {
                    if(current_index < 4-1) {
                        current_index++;
                        moveCurrentPage(true);  //move left
                    }
                    else {
                        moveCurrentPage(false); //move right
                    }
                }
                else {
                    moveCurrentPage(false);     //move right
                }
            }
        }
        mouse_press = false;
    }
//    else if(mouse_move){
//        mouse_move = false;
//    }
}

void SliderPicture::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "SliderPicture::mouseMoveEvent";
    int xPos = 0;
    if(mouse_press) {
        if(label_move) {
            m_mouseDstPos = event->pos();
            xPos = m_mouseDstPos.x() - m_mouseSrcPos.x();

            setLabelMove(false);
            total_label->move(current_pos_x + xPos, 0);
            setLabelMove(true);
        }
    }
//    else if(mouse_move) {
//        m_mouseDstPos = event->pos();
//        this->move(this->pos() + m_mouseDstPos - m_mouseSrcPos);
//    }
}

void SliderPicture::moveCurrentPage(bool direction)
{
    //change all label
    for(int i=0; i<4; i++) {
        if(i != current_index) {
            label_array.at(i)->setStyleSheet(strUnselected);
        }
        else{
            label_array.at(i)->setStyleSheet(strSelected);
        }
    }
    //split point of picture
    //0-680 680-1360 1360-2040 2040-2720
    //true:left     false:right

    //index=0, move -680*0
    //index=1, move -680*1
    //index=2, move-680*2
    //index=3, move-680*3
    setLabelMove(false);
    int current_pos_x = total_label->x();    //label position
    int dest_pos_x = -680 * current_index;
    if(direction) {
        while(current_pos_x > dest_pos_x) {
            total_label->move(current_pos_x-20, 0);
            current_pos_x = total_label->x();
            qApp->processEvents(QEventLoop::AllEvents);
        }
    }
    else {
        while(current_pos_x < dest_pos_x) {
            total_label->move(current_pos_x+20, 0);
            current_pos_x = total_label->x();
            qApp->processEvents(QEventLoop::AllEvents);
        }
    }
    total_label->move(dest_pos_x, 0);
    setLabelMove(true);
}

void SliderPicture::setLabelMove(bool enable)
{
    label_move = enable;
}
