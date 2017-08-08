#ifndef ASSETQUERY_H
#define ASSETQUERY_H

#include "AnimatedPage.h"

namespace Ui {
class AssetQuery;
}

class AssetQuery : public AnimatedPage
{
    Q_OBJECT

public:
    explicit AssetQuery(QWidget *parent = 0);
    ~AssetQuery();

signals:
    void okClicked();
protected:
    void init();
private:
    Ui::AssetQuery *ui;
};

#endif // ASSETQUERY_H
