TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    date.cpp \
    person.cpp \
    testgenerator.cpp

HEADERS += \
    validation/validation.hpp \
    date.h \
    sex.hpp \
    misc/formoption.h \
    person.h \
    testgenerator.h \
    random/random.hpp

QMAKE_CXXFLAGS += -pedantic-errors -Wall -Wextra
