#ifndef APPLICATIONS_H
#define APPLICATIONS_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class Applications;
}

class Applications : public QWidget
{
    Q_OBJECT

public:
    explicit Applications(QWidget *parent = 0);
    ~Applications();
    void setColumn(int count);

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
private:
    void relayout();
private:
    Ui::Applications *ui;

    QButtonGroup *m_btnGrp;
    int m_column = 4;
    int m_row = 2;
};

#endif // APPLICATIONS_H
