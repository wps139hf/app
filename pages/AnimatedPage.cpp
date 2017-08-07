#include "AnimatedPage.h"

#include <QPropertyAnimation>

AnimatedPage::AnimatedPage(QWidget *parent) : BasePage(parent)
{

}

void AnimatedPage::resizeEvent(QResizeEvent *e)
{
    BasePage::resizeEvent(e);

    initAnimation();
}

void AnimatedPage::showEvent(QShowEvent *e)
{
    BasePage::showEvent(e);
    m_animationGrp.start();
}

void AnimatedPage::initAnimation()
{
    if(m_animationGrp.state() == QAbstractAnimation::Running){
        return;
    }
    m_animationGrp.clear();

    QPropertyAnimation *animate = new QPropertyAnimation(this, "geometry", &m_animationGrp);
    animate->setEasingCurve(QEasingCurve::InQuad);
    animate->setDuration(300);
    animate->setStartValue(QRect(width(), 0, width(), height()));
    animate->setEndValue(QRect(0, 0, width(), height()));
    m_animationGrp.addAnimation(animate);
}
