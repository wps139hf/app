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

INCLUDEPATH += src
DEPENDPATH += src

SOURCES += \
        src/main.cpp \
        src/HomePage.cpp \
    src/StyledButton.cpp \
    src/Image.cpp \
    src/ToolBar.cpp \
    src/MainWindow.cpp \
    src/TitleBar.cpp \
    src/AppWidget.cpp \
    src/NoticeWidget.cpp \
    src/MainPages.cpp

HEADERS += \
        src/HomePage.h \
    src/StyledButton.h \
    src/Image.h \
    src/ToolBar.h \
    src/MainWindow.h \
    src/TitleBar.h \
    src/AppWidget.h \
    src/NoticeWidget.h \
    src/MainPages.h

FORMS += \
        src/HomePage.ui \
    src/ToolBar.ui \
    src/MainWindow.ui \
    src/TitleBar.ui \
    src/AppWidget.ui \
    src/NoticeWidget.ui \
    src/MainPages.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res/res.qrc

