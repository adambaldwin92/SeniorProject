QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = src
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    worker.cpp \
    global_objects.cpp \
    main.cpp

HEADERS += \
    worker.h \
    global_objects.h \
#    src_global.h \q
    worker_test.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/release/ -lgtest_main
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/debug/ -lgtest_main
else:unix: LIBS += -L$$PWD/../../../../../usr/src/gtest/ -lgtest_main

INCLUDEPATH += $$PWD/../../../../../usr/src/gtest
DEPENDPATH += $$PWD/../../../../../usr/src/gtest

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/libgtest_main.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/libgtest_main.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/gtest_main.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/gtest_main.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/libgtest_main.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/debug/ -lgtest
else:unix: LIBS += -L$$PWD/../../../../../usr/src/gtest/ -lgtest

INCLUDEPATH += $$PWD/../../../../../usr/src/gtest
DEPENDPATH += $$PWD/../../../../../usr/src/gtest

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/libgtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/libgtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/gtest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/gtest.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/libgtest.a

DISTFILES += \
    ../../../Pictures/imagespanda.jpg
