#ifndef ASSETPAGE_H
#define ASSETPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class AssetPage;
}

class AssetPage : public AnimatedPage
{
    Q_OBJECT

public:
    explicit AssetPage(QWidget *parent = 0);
    ~AssetPage();
signals:
    void inputQcClicked();
protected:
    void init();
private:
    Ui::AssetPage *ui;
};

#endif // ASSETPAGE_H
