QT += core
QT -= gui

CONFIG += c++11

TARGET = src
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    worker.cpp \
    global_objects.cpp \
#    tests.cpp

HEADERS += \
    worker.h \
    global_objects.h
