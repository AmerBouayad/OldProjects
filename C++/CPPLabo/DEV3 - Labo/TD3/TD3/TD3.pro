TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    td3.c

HEADERS += \
    td3.h \
    dllist.h \
    dllist_utility.h \
    dlnode.h \
    dlnode_utility.h \
    value_t.h

QMAKE_CFLAGS += -std=c11 \
-pedantic-errors \
-D__USE_MINGW_ANSI_STDIO
