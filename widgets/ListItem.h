#ifndef LISTITEM_H
#define LISTITEM_H

#include <QLabel>
#include <QMouseEvent>

class ListItem : public QLabel
{
    Q_OBJECT

public:
    explicit ListItem(const QString &text, const QString &key, QWidget *parent = 0);
    ~ListItem();
signals:
    void itemselected(const QString &keyword);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QString m_keyword;
};

#endif // LISTITEM_H
