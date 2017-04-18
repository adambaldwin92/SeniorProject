QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += stdafx.h
PRECOMPILED_HEADER =

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
    camera_test.h \
    power_test.h \
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Programs/googletest-master/googletest/msvc/gtest/release/ -lgtestd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../Programs/googletest-master/googletest/msvc/gtest/debug/ -lgtestd
else:unix: LIBS += -L$$PWD/../../../../../Programs/googletest-master/googletest/msvc/gtest/ -lgtestd

INCLUDEPATH += $$PWD/../../../../../Programs/googletest-master/googletest/include/gtest
DEPENDPATH += $$PWD/../../../../../Programs/googletest-master/googletest/include/gtest

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Programs/googletest-master/googlemock/msvc/2015/release/ -lgmock
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../Programs/googletest-master/googlemock/msvc/2015/debug/ -lgmock
else:unix: LIBS += -L$$PWD/../../../../../Programs/googletest-master/googlemock/msvc/2015/ -lgmock

INCLUDEPATH += $$PWD/../../../../../Programs/googletest-master/googlemock/include/gmock
DEPENDPATH += $$PWD/../../../../../Programs/googletest-master/googlemock/include/gmock

#-----------------------------------------------------------------------------------------------------------------------------------------
#----old includes for gtest with unix system----------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------------------------------------

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/release/ -lgtest_main
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/debug/ -lgtest_main
#else:unix: LIBS += -L$$PWD/../../../../../usr/src/gtest/ -lgtest_main

#INCLUDEPATH += $$PWD/../../../../../usr/src/gtest
#DEPENDPATH += $$PWD/../../../../../usr/src/gtest

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/libgtest_main.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/libgtest_main.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/gtest_main.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/gtest_main.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/libgtest_main.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/release/ -lgtest
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/src/gtest/debug/ -lgtest
#else:unix: LIBS += -L$$PWD/../../../../../usr/src/gtest/ -lgtest

#INCLUDEPATH += $$PWD/../../../../../usr/src/gtest
#DEPENDPATH += $$PWD/../../../../../usr/src/gtest

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/libgtest.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/libgtest.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/release/gtest.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/debug/gtest.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/src/gtest/libgtest.a

#DISTFILES += \
#    ../../../Pictures/imagespanda.jpg

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/release/ -lopencv_core
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/debug/ -lopencv_core
#else:unix: LIBS += -L$$PWD/../../../Programs/opencv/build/lib/ -lopencv_core

#INCLUDEPATH += $$PWD/../../../Programs/opencv/build/include
#DEPENDPATH += $$PWD/../../../Programs/opencv/build/include

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/release/ -lopencv_imgcodecs
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/debug/ -lopencv_imgcodecs
#else:unix: LIBS += -L$$PWD/../../../Programs/opencv/build/lib/ -lopencv_imgcodecs

#INCLUDEPATH += $$PWD/../../../Programs/opencv/build/include
#DEPENDPATH += $$PWD/../../../Programs/opencv/build/include

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/release/ -lopencv_highgui
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Programs/opencv/build/lib/debug/ -lopencv_highgui
#else:unix: LIBS += -L$$PWD/../../../Programs/opencv/build/lib/ -lopencv_highgui

#INCLUDEPATH += $$PWD/../../../Programs/opencv/build/include
#DEPENDPATH += $$PWD/../../../Programs/opencv/build/include

