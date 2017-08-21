#include "AbstractPageManager.h"
#include "AnimatedPage.h"
#include <QTimer>

AbstractPageManager::AbstractPageManager(QWidget *parent)
    : QWidget(parent)
{

}

void AbstractPageManager::initilize()
{
    for(auto child : children()){
        QWidget *widget = qobject_cast<QWidget *>(child);
        if(widget){
            widget->hide();
            m_pageList.append(widget);
        }

        BasePage *page = qobject_cast<BasePage*>(widget);
        if(page){
            connect(page, SIGNAL(error(QString)), this, SIGNAL(error(QString)));
        }
    }

    setupConnections();
}

void AbstractPageManager::showPage(QWidget *page)
{
    m_prevPage = m_curPage;
    m_curPage = page;

    page->show();
    page->raise();
    QTimer::singleShot(ANIMATION_DURATION, this, [this, page](){
        for(auto p : m_pageList){
            if(p != page){
                p->hide();
            }
        }
    });
}

void AbstractPageManager::showPrevPage()
{
    if(m_prevPage){
//        QWidget *page = m_prevPage;
//        showPage(page);
        m_prevPage->show();
        m_prevPage->raise();
        m_curPage->hide();

        QWidget *page = m_prevPage;
        m_prevPage = m_curPage;
        m_curPage = page;
    }
}

void AbstractPageManager::sendError(const QString &err)
{
    emit error(err);
}

void AbstractPageManager::setupConnections()
{

}

void AbstractPageManager::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    for(auto page : m_pageList){
        page->resize(size());
        page->move(0, 0);
    }
}
