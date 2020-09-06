TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp


QMAKE_CXXFLAGS += -pedantic-errors
