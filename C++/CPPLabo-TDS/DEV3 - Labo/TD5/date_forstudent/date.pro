TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    date.cpp

HEADERS += \
    date.h \
    validation.hpp

CONFIG += c++14
QMAKE_CXXFLAGS += -pedantic-errors

