#ifndef ANIMATEDPAGE_H
#define ANIMATEDPAGE_H

#include "BasePage.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#define ANIMATION_DURATION  300

class AnimatedPage : public BasePage
{
    Q_OBJECT
public:
    explicit AnimatedPage(QWidget *parent = nullptr);

signals:

public slots:
protected:
    void resizeEvent(QResizeEvent *e);
    void showEvent(QShowEvent *e);
private:
    void initAnimation();
    QParallelAnimationGroup m_animationGrp;
};

#endif // ANIMATEDPAGE_H
