
include(../gtest_dependency.pri)

QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \    
    mock_foo.h \
    tst_pump.h \
    tst_foo.h \
    pump.h \
    global_objects.h \
    power.h \
    mainwindow.h \
    pump.h \
    interfaces.h \
    mocks.h \
    tst_camera.h \
    tst_power.h

SOURCES +=    \
    main.cpp \
#    _tmain.cpp \
    pump.cpp \
    global_objects.cpp \
    power.cpp \
    mainwindow.cpp \
    pump.cpp

FORMS += \
    mainwindow.ui

DISTFILES += \
    start.cmd


#INCLUDEPATH += $$PWD/'../../../../../../../../Program Files/Boost/include'
#DEPENDPATH += $$PWD/'../../../../../../../../Program Files/Boost/include'


unix|win32: LIBS += -L$$PWD/'../../../../../../../../Program Files/Thorlabs/Scientific Imaging/DCx Camera Support/Develop/Lib/' -luc480_64

INCLUDEPATH += $$PWD/'../../../../../../../../Program Files/Thorlabs/Scientific Imaging/DCx Camera Support/Develop/Include'
DEPENDPATH += $$PWD/'../../../../../../../../Program Files/Thorlabs/Scientific Imaging/DCx Camera Support/Develop/Include'


