TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

HEADERS +=

QMAKE_CFLAGS += -std=c99 \
                -pedantic-errors \
                -D__USE_MINGW_ANSI_STDIO
