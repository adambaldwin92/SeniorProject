CONFIG -= qt
CONFIG += qt

QT  += network core concurrent

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TARGET = app

SOURCES += main.cpp \
    power.cpp

HEADERS += \
    power.h \
    pump.h \
    client.h \
    server.h \
    thread.h
