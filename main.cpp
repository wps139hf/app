#include "MainWindow.h"
#include "qDebug2Logcat.h"

#include "qtsoap.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    installLogcatMessageHandler("APP");

    qRegisterMetaType<QtSoapMessage>("QtSoapMessage");

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    MainWindow::instance()->show();

    return a.exec();
}
