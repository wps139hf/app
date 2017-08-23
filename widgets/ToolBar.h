#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class ToolBar;
}

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    enum Button{
        Message = 0,
        Home,
        Mine
    };

    explicit ToolBar(QWidget *parent = 0);
    ~ToolBar();
    void setChecked(int btnIndex);
signals:
    void clicked(int btnIndex);

protected:
//    void resizeEvent(QResizeEvent *e);
//    void paintEvent(QPaintEvent *e);
private:
    void relayout();

private:
    Ui::ToolBar *ui;
    QButtonGroup *m_btnGrp;
};

#endif // TOOLBAR_H
