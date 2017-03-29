include(../gtest_dependency.pri)

TARGET = foo
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QT += widgets

HEADERS +=     tst_foo.h \
    tst_power.h \
    tst_pump.h

SOURCES +=     main.cpp
