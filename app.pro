#-------------------------------------------------
#
# Project created by QtCreator 2017-08-04T16:21:07
#
#-------------------------------------------------

QT       += core gui network xml concurrent

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

INCLUDEPATH += pages utils widgets models
DEPENDPATH += pages utils widgets models

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
    widgets/SliderPicture.cpp \
    pages/PageManager.cpp \
    pages/WelcomePage.cpp \
    pages/LoginPage.cpp \
    pages/AnimatedPage.cpp \
    pages/CarPage.cpp \
    pages/RepairPage.cpp \
    pages/BuyPage.cpp \
    pages/PrintPage.cpp \
    pages/RoomPage.cpp \
    pages/AssetQuery.cpp \
    pages/AssetInfo.cpp \
    pages/AssetScan.cpp \
    pages/AbstractPageManager.cpp \
    pages/BusyPage.cpp \
    utils/qtsoap.cpp \
    models/ApplicationModel.cpp \
    models/ModelManager.cpp \
    models/AbstractModel.cpp \
    models/AssetModel.cpp \
    models/AbstractData.cpp \
    models/CarModel.cpp \
    models/MutiRoomModel.cpp \
    pages/RoomList.cpp \
    models/SoapMessage.cpp \
    utils/JSON.cpp \
    widgets/Notification.cpp \
    widgets/ListItem.cpp \
    widgets/StyledList.cpp

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
    widgets/SliderPicture.h \
    pages/PageManager.h \
    pages/WelcomePage.h \
    pages/LoginPage.h \
    pages/AnimatedPage.h \
    pages/CarPage.h \
    pages/RepairPage.h \
    pages/BuyPage.h \
    pages/PrintPage.h \
    pages/RoomPage.h \
    pages/AssetQuery.h \
    pages/AssetInfo.h \
    pages/AssetScan.h \
    pages/AbstractPageManager.h \
    pages/BusyPage.h \
    utils/qtsoap.h \
    models/ApplicationModel.h \
    models/ModelManager.h \
    models/AbstractModel.h \
    models/AssetModel.h \
    models/AbstractData.h \
    models/CarModel.h \
    models/MutiRoomModel.h \
    pages/RoomList.h \
    models/SoapMessage.h \
    utils/JSON.h \
    widgets/Notification.h \
    widgets/ListItem.h \
    widgets/StyledList.h

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
    pages/RepairPage.ui \
    pages/BuyPage.ui \
    pages/PrintPage.ui \
    pages/RoomPage.ui \
    pages/AssetQuery.ui \
    pages/AssetInfo.ui \
    pages/AssetScan.ui \
    pages/BusyPage.ui \
    pages/RoomPage2.ui \
    pages/RoomList.ui \
    widgets/Notification.ui \
    widgets/ListItem.ui \
    widgets/StyledList.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res/res.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml \
    res/fonts/microsoftyh.ttf
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

