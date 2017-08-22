#include "MainWindow.h"
#include "qDebug2Logcat.h"

#include "qtsoap.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    installLogcatMessageHandler("APP");

    qRegisterMetaType<QtSoapMessage>("QtSoapMessage");

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    //set font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/MicrosoftYaHei.ttf");
    QString androidFont = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(androidFont);
    a.setFont(font);

    MainWindow::instance()->show();

    return a.exec();
}
