include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_foo.h \
    tst_power.h \
    tst_pump.h

SOURCES +=     main.cpp
