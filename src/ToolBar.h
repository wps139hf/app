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
    explicit ToolBar(QWidget *parent = 0);
    ~ToolBar();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    Ui::ToolBar *ui;
    QButtonGroup *m_btnGrp;
};

#endif // TOOLBAR_H
