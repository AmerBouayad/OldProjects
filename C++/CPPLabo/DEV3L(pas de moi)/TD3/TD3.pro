TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    03-DLList.c \
    01-DLNode.c \
    02-DLNode_Ut.c \
    04-DLList_Ut.c

HEADERS += \
    value_t.h \
    dlnode.h \
    dlnode_utility.h \
    dllist.h \
    dllist_utlity.h

