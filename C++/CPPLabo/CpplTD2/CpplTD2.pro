-TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11 \
                -pedantic-errors \
                -D__USE_MINGW_ANSI_STDIO

SOURCES += main.c \
    exo.c \
    ../BouayadAmer42392Td1Dev3l/mathesi.c

HEADERS += \
    td2.h \
    ../BouayadAmer42392Td1Dev3l/mathesi.h
