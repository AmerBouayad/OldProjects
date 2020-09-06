TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    td2.c

HEADERS += \
    td2.h

QMAKE_CFLAGS += -std=c99 \
                -pedantic-errors \
                -D__USE_MINGW_ANSI_STDIO
