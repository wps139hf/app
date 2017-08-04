#ifndef STYLEDBUTTON_H
#define STYLEDBUTTON_H

#include <QAbstractButton>

class StyledButton : public QAbstractButton
{
    Q_OBJECT
public:
    explicit StyledButton(QWidget *parent = nullptr);
    void setImage(const QImage &image);

public slots:
    void setMsgCount(int count);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    int textHeight();
    QRect getBoundary(QPainter &painter);
    void draw(QPainter &painter, const QRect &rc);
    void drawMsg(QPainter &painter);

private:
    QImage m_image;
    QImage m_mask;
    int m_msgCount = 0;
    int m_gap = 10;
    bool m_isPressed = false;
};

#endif // STYLEDBUTTON_H
