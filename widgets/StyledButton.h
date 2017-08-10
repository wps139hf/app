#ifndef STYLEDBUTTON_H
#define STYLEDBUTTON_H

#if 0

#include <QAbstractButton>

class StyledButton : public QAbstractButton
{
    Q_OBJECT
public:
    explicit StyledButton(QWidget *parent = nullptr);
    void setPixmap(const QPixmap &pixmap);

public slots:
    void setMsgCount(int count);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    int textHeight();
    QRect getBoundary(QPainter &painter);
    void drawBackground(QPainter &painter);
    void drawImage(QPainter &painter, const QRect &rc);
    void drawText(QPainter &painter, const QRect &rc);
    void drawMsg(QPainter &painter);

private:
    QImage m_image;
    QImage m_mask;
    int m_msgCount = 0;
    int m_gap = 10;
    bool m_isPressed = false;
};
#else
#include <QToolButton>
class StyledButton : public QToolButton
{
    Q_OBJECT
public:
    explicit StyledButton(QWidget *parent = nullptr);
    void setPixmap(const QPixmap &pixmap);
public slots:
    void setMsgCount(int count);

protected:
    void paintEvent(QPaintEvent *e);
private:
    void drawMsg(QPainter &painter);
    int m_msgCount = 0;
};
#endif

#endif // STYLEDBUTTON_H
