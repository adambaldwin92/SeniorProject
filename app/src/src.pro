CONFIG -= qt
CONFIG += qt

QT  += network core concurrent widgets

CONFIG += console
CONFIG -= app_bundle

TARGET = app
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += \
    power.cpp \
    thread.cpp

HEADERS += \
    src_global.h \
    power.h \
    pump.h \
    client.h \
    server.h \
    thread.h \
    src_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
