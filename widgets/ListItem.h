#ifndef LISTITEM_H
#define LISTITEM_H

#include <QLabel>
#include <QMouseEvent>

class ListItem : public QLabel
{
    Q_OBJECT

public:
    explicit ListItem(const QString &text, int index, QWidget *parent = 0);
    ~ListItem();
signals:
    void itemselected(int index);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    int m_index = 0;
};

#endif // LISTITEM_H
