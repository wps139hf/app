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
    void showPrevPage();
    void sendError(const QString &err);
signals:
    void notified(const QString &err);
protected:
    virtual void setupConnections();
    void resizeEvent(QResizeEvent *e);
private:
    QList<QWidget *>m_pageList;
    QWidget *m_prevPage = Q_NULLPTR;
    QWidget *m_curPage = Q_NULLPTR;
};

#endif // ABSTRACTPAGEMANAGER_H
