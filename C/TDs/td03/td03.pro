TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11 \
-pedantic-errors \
#-D__USE_MINGW_ANSI_STDIO

SOURCES += main.c \
    dlnode.c \
    dlnode_utility.c \
    dllist.c \
    dllist_utility.c

HEADERS += \
    value_t.h \
    dlnode.h \
    dllist.h \
    dllist_utility.h \
    dlnode_utility.h
