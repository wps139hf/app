#include "MainWindow.h"
#include "qDebug2Logcat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    installLogcatMessageHandler("APP");

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
