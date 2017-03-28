TEMPLATE = subdirs

SUBDIRS += src

CONFIG(debug, debug|release) {
    SUBDIRS += tests
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../libraries/googletest-master/googletest/msvc/gtest-md/release/ -lgtestd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../libraries/googletest-master/googletest/msvc/gtest-md/debug/ -lgtestd
else:unix: LIBS += -L$$PWD/../../../../../libraries/googletest-master/googletest/msvc/gtest-md/ -lgtestd

INCLUDEPATH += $$PWD/../../../../../libraries/googletest-master/googletest/include
DEPENDPATH += $$PWD/../../../../../libraries/googletest-master/googletest/include
