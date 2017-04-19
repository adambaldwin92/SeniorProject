
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \    
    tst_pump.h \
    tst_power.h \
    tst_camera.h

SOURCES +=     main.cpp
