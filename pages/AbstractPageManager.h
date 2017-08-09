#ifndef ABSTRACTPAGEMANAGER_H
#define ABSTRACTPAGEMANAGER_H

#include <QWidget>

class AbstractPageManager : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPageManager(QWidget *parent = 0);
    /**
     * @brief initilize be invoked by its child.
     */
    void initilize();
    /**
     * @brief showPage
     * @param page
     */
    void showPage(QWidget *page);
protected:
    virtual void setupConnections();
    void resizeEvent(QResizeEvent *e);
private:
    QList<QWidget *>m_pageList;
};

#endif // ABSTRACTPAGEMANAGER_H
