#-------------------------------------------------
#
# Project created by QtCreator 2015-10-05T17:01:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = picture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp Picture.cpp

HEADERS  += mainwindow.h Picture.h formList.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/images/icons.qrc
