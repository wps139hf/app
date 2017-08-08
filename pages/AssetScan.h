#ifndef ASSETPAGE_H
#define ASSETPAGE_H

#include "AnimatedPage.h"

namespace Ui {
class AssetScan;
}

class AssetScan : public AnimatedPage
{
    Q_OBJECT

public:
    explicit AssetScan(QWidget *parent = 0);
    ~AssetScan();
signals:
    void inputQcClicked();
protected:
    void init();
private:
    Ui::AssetScan *ui;
};

#endif // ASSETPAGE_H
