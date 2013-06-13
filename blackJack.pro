#-------------------------------------------------
#
# Project created by QtCreator 2013-06-13T10:14:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = blackJack
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += include/

SOURCES += main.cpp \
src/Card.cpp \
src/Deck.cpp \
src/BJConsoleView.cpp

HEADERS += include/Card.h \
include/Deck.h \
include/BJConsoleView.h
