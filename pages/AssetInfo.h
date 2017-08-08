#ifndef ASSETINFO_H
#define ASSETINFO_H

#include "AnimatedPage.h"

namespace Ui {
class AssetInfo;
}

class AssetInfo : public AnimatedPage
{
    Q_OBJECT

public:
    explicit AssetInfo(QWidget *parent = 0);
    ~AssetInfo();

protected:
    void init();
private:
    Ui::AssetInfo *ui;
};

#endif // ASSETINFO_H
