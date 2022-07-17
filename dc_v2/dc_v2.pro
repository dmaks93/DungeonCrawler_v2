TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractui.cpp \
        active.cpp \
        character.cpp \
        dungeoncrawler.cpp \
        level.cpp \
        main.cpp \
        passive.cpp \
        tile.cpp

HEADERS += \
    abstractui.h \
    active.h \
    character.h \
    dungeoncrawler.h \
    level.h \
    passive.h \
    tile.h
