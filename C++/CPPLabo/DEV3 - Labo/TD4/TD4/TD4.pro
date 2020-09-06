TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    td4.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    td4.h \
    random.h
