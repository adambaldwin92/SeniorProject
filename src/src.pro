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
    service_module.cpp \
    module.cpp \
    worker.cpp \
    global_objects.cpp \
    camera.cpp \
    power.cpp

HEADERS += \
    src_global.h \
    service_module.h \
    module.h \
    worker.h \
    global_objects.h \
    camera.h \
    power.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
