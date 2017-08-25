#include "ListItem.h"
#include <QDebug>

#if 0
#define NORMAL_STYLE "QLabel{" \
    "border: 1px solid gray;"\
    "background-color: rgb(220, 220, 220);"\
    "border-radius: 6px;"\
    "padding-left:20px;"\
 "}"

#define PRESS_STYLE "QLabel{" \
    "border: 1px solid gray;"\
    "background-color: rgb(188, 188, 200);"\
    "border-radius: 6px;"\
    "padding-left:20px;"\
 "}"
#endif

#define NORMAL_STYLE    "background-color:white; "\
    "font-family:Microsoft YaHei;" \
    "font-size:14pt;"\
    "border:none;"\
    "border-radius:0px;"

#define PRESS_STYLE    "background-color:rgb(150,150,150,150); "\
    "font-family:Microsoft YaHei;" \
    "font-size:14pt;"\
    "border:none;"\
    "border-radius:0px;"

ListItem::ListItem(const QString &text, int index, QWidget *parent)
    : QLabel(parent)
{
    setStyleSheet(NORMAL_STYLE);
    setText("<u>" + text + "</u>");
    m_index = index;
    setFixedHeight(40);
}

ListItem::~ListItem()
{
}

void ListItem::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setStyleSheet(PRESS_STYLE);
}

void ListItem::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setStyleSheet(NORMAL_STYLE);
    emit itemselected(m_index);
}
