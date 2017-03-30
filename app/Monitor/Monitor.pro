#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T00:25:35
#
#-------------------------------------------------

CONFIG -= qt
CONFIG += qt

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lapp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lapp
else:unix: LIBS += -L$$OUT_PWD/../src/ -lapp

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
