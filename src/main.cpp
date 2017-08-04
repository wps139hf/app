#include "HomePage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage w;
//    w.setFixedSize(400, 600);
    w.show();

    return a.exec();
}
