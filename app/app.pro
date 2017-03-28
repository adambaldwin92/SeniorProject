TEMPLATE = subdirs

SUBDIRS += src \
    Monitor


CONFIG(debug, debug|release) {
    SUBDIRS += tests
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/src/release/ -lapp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/src/debug/ -lapp
else:unix: LIBS += -L$$OUT_PWD/src/ -lapp

INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src
