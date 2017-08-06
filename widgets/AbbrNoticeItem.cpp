#include "AbbrNoticeItem.h"

AbbrNoticeItem::AbbrNoticeItem()
    : QListWidgetItem()
{
    setIcon(QIcon("://icons/icon-mark.png"));
}

AbbrNoticeItem::AbbrNoticeItem(const QString &text)
    : QListWidgetItem(text)
{
    setIcon(QIcon("://icons/icon-mark.png"));
}
