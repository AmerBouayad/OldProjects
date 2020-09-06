TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors

SOURCES += \
    mathesi.cpp \
    main.cpp \
    surchage_01.cpp \
    surcharge_02.cpp \
    surcharge_03.cpp \
    surcharge_04.cpp

HEADERS += \
    mathesi.h \
    random.hpp
