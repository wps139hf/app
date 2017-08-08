#include "AnimatedPage.h"

#include <QPropertyAnimation>

AnimatedPage::AnimatedPage(QWidget *parent) : BasePage(parent)
{

}

void AnimatedPage::setAnimationStyle(AnimatedPage::Style style)
{
    m_style = style;
    initAnimation();
}

void AnimatedPage::resizeEvent(QResizeEvent *e)
{
    BasePage::resizeEvent(e);

    initAnimation();
}

void AnimatedPage::showEvent(QShowEvent *e)
{
    BasePage::showEvent(e);
    m_aniGrp.start();
}

void AnimatedPage::initAnimation()
{
    if(m_aniGrp.state() == QAbstractAnimation::Running){
        return;
    }
    m_aniGrp.clear();

    QPropertyAnimation *ani = new QPropertyAnimation(this, "geometry", &m_aniGrp);
    ani->setEasingCurve(ANIMATION_EASING_CURVE);
    ani->setDuration(ANIMATION_DURATION);
    switch(m_style){
    case FromRight:
        ani->setStartValue(QRect(width(), 0, width(), height()));
        ani->setEndValue(QRect(0, 0, width(), height()));
        break;
    case FromTop:
        ani->setStartValue(QRect(0, -height(), width(), height()));
        ani->setEndValue(QRect(0, 0, width(), height()));
        break;
    case FromLeft:
        ani->setStartValue(QRect(-width(), 0, width(), height()));
        ani->setEndValue(QRect(0, 0, width(), height()));
        break;
    case FromBottom:
        ani->setStartValue(QRect(0, height(), width(), height()));
        ani->setEndValue(QRect(0, 0, width(), height()));
        break;
    default:break;
    }

    m_aniGrp.addAnimation(ani);
}
