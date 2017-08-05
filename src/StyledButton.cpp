#include "StyledButton.h"

#include <QPainter>
#include <QDebug>
#include <QRect>

StyledButton::StyledButton(QWidget *parent)
    : QAbstractButton(parent)
{

}

void StyledButton::setImage(const QImage &image)
{
    m_image = image.scaledToHeight(rect().height()/2);
    update();
}

void StyledButton::setMsgCount(int count)
{
    m_msgCount = count;
    update();
}

void StyledButton::mousePressEvent(QMouseEvent *e)
{
    QAbstractButton::mousePressEvent(e);
    m_isPressed = true;
    update();
}

void StyledButton::mouseReleaseEvent(QMouseEvent *e)
{
    QAbstractButton::mouseReleaseEvent(e);
    m_isPressed = false;
    update();
}

void StyledButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing);

    //get the real rect that will draw image and text in
    QRect rc = getBoundary(painter);
    rc.moveTo(0, rect().height()/2 - rc.height()/2);

    drawBackground(painter);

    drawImage(painter, rc);

    if(!text().isEmpty()){
        drawText(painter, rc);
    }

    if(m_msgCount){
        drawMsg(painter);
    }
}

int StyledButton::textHeight()
{
    QFontMetrics metric(font());
    return metric.height();
}

QRect StyledButton::getBoundary(QPainter &painter)
{
    int gap = painter.device()->devicePixelRatioF() * m_gap;
    //get the real rect that will draw image and text in
    return QRect(rect().x(), 0, rect().width(), m_image.rect().height() + gap + textHeight());
}

void StyledButton::drawBackground(QPainter &painter)
{
    //draw background if selected
    if(isChecked()){
        QPen pen;
        pen.setColor(Qt::blue);
        painter.setPen(pen);
        painter.setBrush(Qt::blue);
//        painter.drawRoundRect(rect(), 30, 30);
        painter.drawRect(rect());
    }
}

void StyledButton::drawImage(QPainter &painter, const QRect &rc)
{
    painter.drawImage(rc.left() + rc.width()/2 - m_image.width()/2, rc.top(), m_image);
    if(m_isPressed){
        m_mask = QImage(m_image.size(), QImage::Format_ARGB32);
        m_mask.fill(QColor(0, 0, 0, 100));

        painter.drawImage(rc.left() + rc.width()/2 - m_image.width()/2, rc.top(), m_mask);
    }
}

void StyledButton::drawText(QPainter &painter, const QRect &rc)
{
    //draw text
    QPen pen;
    if(isChecked()){
        pen.setColor(Qt::white);
    }else{
        pen.setColor(Qt::black);
    }
    painter.setPen(pen);

    int h = textHeight();
    QRect textRect = QRect(rect().x(), rc.bottom() - h, rect().width(), h);
    painter.drawText(textRect, Qt::AlignCenter, text());
}

void StyledButton::drawMsg(QPainter &painter)
{
    if(m_msgCount < 100){
        //text background
        QPen pen;
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.setBrush(Qt::red);

        QRect rc(rect().right() - 20, rect().top(), 20, 20);
        painter.drawEllipse(rc);
        //text
        pen.setColor(Qt::white);
        painter.setPen(pen);
        QFont font;
        font.setPointSize(10);//text font size
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(rc, Qt::AlignCenter, QString().setNum(m_msgCount));
    }else{
        //too many message
        QPen pen;
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.setBrush(Qt::red);

        QRect rc(rect().right() - 10, rect().top(), 10, 10);
        painter.drawEllipse(rc);
    }
}
