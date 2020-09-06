TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    isprime.c

HEADERS += \
    isprime.h

QMAKE_CFLAGS += -std=c99 \
                -pedantic-errors \
                -D__USE_MINGW_ANSI_STDIO
