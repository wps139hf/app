#-------------------------------------------------
#
# Project created by QtCreator 2017-08-04T16:21:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += pages utils widgets
DEPENDPATH += pages utils widgets

SOURCES += \
    main.cpp \
    pages/HomePage.cpp \
    widgets/StyledButton.cpp \
    utils/Image.cpp \
    widgets/ToolBar.cpp \
    MainWindow.cpp \
    widgets/TitleBar.cpp \
    widgets/AppWidget.cpp \
    widgets/NoticeWidget.cpp \
    pages/BasePage.cpp \
    utils/qDebug2Logcat.cpp \
    widgets/AbbrNoticeItem.cpp \
    pages/NoticeDisplay.cpp \
    pages/MessagePage.cpp \
    pages/MinePage.cpp \
    widgets/sliderpicture.cpp \
    pages/PageManager.cpp \
    pages/WelcomePage.cpp \
    pages/LoginPage.cpp \
    pages/AnimatedPage.cpp \
    pages/CarPage.cpp \
    pages/RepairPage.cpp

HEADERS += \
    pages/HomePage.h \
    widgets/StyledButton.h \
    utils/Image.h \
    widgets/ToolBar.h \
    MainWindow.h \
    widgets/TitleBar.h \
    widgets/AppWidget.h \
    widgets/NoticeWidget.h \
    pages/BasePage.h \
    utils/qDebug2Logcat.h \
    widgets/AbbrNoticeItem.h \
    pages/NoticeDisplay.h \
    pages/MessagePage.h \
    pages/MinePage.h \
    widgets/sliderpicture.h \
    pages/PageManager.h \
    pages/WelcomePage.h \
    pages/LoginPage.h \
    pages/AnimatedPage.h \
    pages/CarPage.h \
    pages/RepairPage.h

FORMS += \
    pages/HomePage.ui \
    widgets/ToolBar.ui \
    MainWindow.ui \
    widgets/TitleBar.ui \
    widgets/AppWidget.ui \
    widgets/NoticeWidget.ui \
    pages/NoticeDisplay.ui \
    pages/MessagePage.ui \
    pages/MinePage.ui \
    pages/PageManager.ui \
    pages/WelcomePage.ui \
    pages/LoginPage.ui \
    pages/CarPage.ui \
    pages/RepairPage.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res/res.qrc

