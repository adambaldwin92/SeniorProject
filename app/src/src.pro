QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += stdafx.h


TARGET = src
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    global_objects.cpp \
#    test_main.cpp \
    main.cpp \
    camera.cpp \
    power.cpp \
    mainwindow.cpp \
    pump.cpp \
    serial.cpp

HEADERS += \
    global_objects.h \
#    src_global.h \q
    camera.h \
    power.h \
#    camera_test.h \
#    power_test.h \
    mainwindow.h \
    pump.h \
    serial.h \
    stdafx.h

FORMS += \
    mainwindow.ui


unix {
    target.path = /usr/lib
    INSTALLS += target
}

