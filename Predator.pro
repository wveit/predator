TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    board.cpp \
    creature.cpp \
    predator.cpp \
    prey.cpp

HEADERS += \
    game.h \
    board.h \
    creature.h \
    predator.h \
    prey.h

