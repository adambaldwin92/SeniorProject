include(../gtest_dependency.pri)

TARGET = test
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QT += widgets

HEADERS +=     tst_foo.h \
    tst_power.h \
    test_suite.h

SOURCES +=     main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../src/release/ -lapp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../src/debug/ -lapp
else:unix: LIBS += -L$$OUT_PWD/../../../src/ -lapp

INCLUDEPATH += $$PWD/../../../src
DEPENDPATH += $$PWD/../../../src

DISTFILES += \
    TODO.txt
