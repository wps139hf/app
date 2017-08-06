#ifndef SLIDERPICTURE_H
#define SLIDERPICTURE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include <QHBoxLayout>
#include <QVector>
#include <QDebug>
/************SliderPicture**************/
class SliderPicture : public QWidget
{
    Q_OBJECT

public:
    explicit SliderPicture(QWidget *parent = 0);
    ~SliderPicture();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void moveCurrentPage(bool);
    void setLabelMove(bool);

private:
    QLabel *background_label;
    QPoint m_mouseSrcPos;
    QPoint m_mouseDstPos;
    bool mouse_press;
//    bool mouse_move;
    bool label_move;
    int current_index;
    QLabel *total_label;
    QVector<QLabel*>label_array;

    QString strSelected;
    QString strUnselected;
    int current_pos_x;
};

#endif // SLIDERPICTURE_H
