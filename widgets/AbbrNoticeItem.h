#ifndef ABBRNOTICEITEM_H
#define ABBRNOTICEITEM_H

#include <QListWidgetItem>

class AbbrNoticeItem : public QListWidgetItem
{
public:
    explicit AbbrNoticeItem();
    explicit AbbrNoticeItem(const QString &text);

signals:

public slots:
};

#endif // ABBRNOTICEITEM_H
