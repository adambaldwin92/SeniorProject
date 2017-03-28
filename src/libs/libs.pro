#-------------------------------------------------
#
# Project created by QtCreator 2017-03-19T23:06:28
#
#-------------------------------------------------

QT       -= gui

TARGET = libs
TEMPLATE = lib

DEFINES += LIBS_LIBRARY

SOURCES += myclass.cpp \
    foo.cpp

HEADERS += myclass.h\
        libs_global.h \
    foo.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
