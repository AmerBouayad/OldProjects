TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mathesi.cpp \
    surcharge_01.cpp \
#    surcharge_02.cpp \
#    surcharge_03.cpp \
    surcharge_04.cpp

HEADERS += mathesi.h \
    surcharge_01.h \
#    surcharge_02.h \
#    surcharge_03.h \
    surcharge_04.h \
    random.hpp \
    container_utility.hpp

QMAKE_CFLAGS += -pedantic-errors
