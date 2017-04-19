
include(../gtest_dependency.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \    
    mock_foo.h \
    mock_camera.h \
    mock_pump.h \
    tst_pump.h \
    tst_foo.h \
    pump.h \
    global_objects.h \
    camera.h \
    power.h \
    mainwindow.h \
    pump.h \
    serial.h \
    stdafx.h \
    rs232.h

SOURCES +=    \
    main.cpp \
#    _tmain.cpp \
    pump.cpp \
    global_objects.cpp \
    camera.cpp \
    power.cpp \
    mainwindow.cpp \
    pump.cpp \
    serial.cpp \
    rs232.c

FORMS += \
    mainwindow.ui
