#ifndef ANIMATEDPAGE_H
#define ANIMATEDPAGE_H

#include "BasePage.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#define ANIMATION_DURATION  (200)
#define ANIMATION_EASING_CURVE    (QEasingCurve::InOutQuad)

class AnimatedPage : public BasePage
{
    Q_OBJECT
public:
    enum Style{
        FromRight,
        FromTop,
        FromLeft,
        FromBottom
    };

    explicit AnimatedPage(QWidget *parent = nullptr);

    void setAnimationStyle(AnimatedPage::Style style);
protected:
    void resizeEvent(QResizeEvent *e);
    void showEvent(QShowEvent *e);
private:
    void initAnimation();
    QParallelAnimationGroup m_aniGrp;

    Style m_style = FromRight;
};

#endif // ANIMATEDPAGE_H
