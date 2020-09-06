-TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11 \
                -pedantic-errors \
                -D__USE_MINGW_ANSI_STDIO

SOURCES += main.c \
    exo.c

HEADERS += \
    td3.h
