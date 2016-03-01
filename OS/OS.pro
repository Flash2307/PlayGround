#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T23:07:20
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

TARGET = OS
TEMPLATE = app

INCLUDEPATH += ./src

SOURCES += main.cpp \
    src/HomeWindow.cpp \
    src/GamePadCom.cpp \
    tests/GamepadMsgServerTest.cpp \
    tests/Fixtures/FakeGamepad.cpp \
    src/UserProfilPage.cpp \
    src/GameSelection.cpp

HEADERS  += HomeWindow.h \
    src/HomeWindow.h \
    src/GamePadCom.h \
    src/GamepadMsg.h \
    tests/GamepadMsgServerTest.h \
    tests/Fixtures/FakeGamepad.h \
    src/UserProfilPage.h \
    src/GameSelection.h
