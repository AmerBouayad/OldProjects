TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    primeFactorA.c \
    primeFactorB.c \
    primeFactorC.c
QMAKE_CFLAGS += -std=c99 \ #Accepter tout ce qui est dans le standart
                -pedantic-errors \ #N'accepte rien de plus
                -D__USE_MINGW_ANSI_STDIO #regler le probleme de long long sur l'affichage

HEADERS += \
    td2.h

