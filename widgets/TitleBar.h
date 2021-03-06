#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    enum Button{
        Back,
        Custom
    };

    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

    void setButtonVisible(TitleBar::Button btn, bool visible);
    void setText(const QString &text);

signals:
    void backClicked(bool);
    void customClicked(bool);

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *event);

private:
    Ui::TitleBar *ui;
};

#endif // TITLEBAR_H
