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

HEADERS  += mainwindow.h Picture.h \
    parameter.h ellipse.h rectangle.h\
    form.h line.h polyline.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/images/icons.qrc
