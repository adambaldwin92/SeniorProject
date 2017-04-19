
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \    
    mock_foo.h \
    mock_camera.h \
    mock_pump.h \
    tst_pump.h \
    tst_foo.h

SOURCES +=    \
     main.cpp
    tst_pump.cpp


