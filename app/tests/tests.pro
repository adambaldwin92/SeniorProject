TEMPLATE = subdirs

SUBDIRS += auto

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files/Boost/lib/' -lboost_filesystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files/Boost/lib/' -lboost_filesystemd
else:unix: LIBS += -L$$PWD/'../../../../../../Program Files/Boost/lib/' -lboost_filesystem

INCLUDEPATH += $$PWD/'../../../../../../Program Files/Boost/include'
DEPENDPATH += $$PWD/'../../../../../../Program Files/Boost/include'

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../../../Program Files/Boost/lib/libboost_filesystem.a'
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../../../Program Files/Boost/lib/libboost_filesystemd.a'
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../../../Program Files/Boost/lib/boost_filesystem.lib'
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/'../../../../../../Program Files/Boost/lib/boost_filesystemd.lib'
else:unix: PRE_TARGETDEPS += $$PWD/'../../../../../../Program Files/Boost/lib/libboost_filesystem.a'
