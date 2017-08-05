#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class AppWidget;
}

class AppWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AppWidget(QWidget *parent = 0);
    ~AppWidget();
    void setColumn(int count);

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
private:
    void relayout();
private:
    Ui::AppWidget *ui;

    QButtonGroup *m_btnGrp;
    int m_column = 4;
    int m_row = 2;
};

#endif // APPWIDGET_H
