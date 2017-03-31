CONFIG -= qt
CONFIG += qt

QT  += network core concurrent
QT  += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console
CONFIG -= app_bundle

TARGET = app
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += \
    power.cpp

HEADERS += \
    src_global.h \
    interfaces.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
