#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T23:07:20
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += testlib
QT       += serialport

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
    src/GameSelection.cpp \
    src/DatabaseFacade.cpp \
    tests/UserProfilPageTest.cpp \
    src/FileLoader.cpp \
    src/CommandSimulator.cpp \
    src/GameProcess.cpp \
    src/SelectableWidget.cpp \
    tests/GamepadMsgSerialTest.cpp

HEADERS  += HomeWindow.h \
    src/HomeWindow.h \
    src/GamePadCom.h \
    src/GamepadMsg.h \
    tests/GamepadMsgServerTest.h \
    tests/Fixtures/FakeGamepad.h \
    src/UserProfilPage.h \
    src/GameSelection.h \
    src/DatabaseFacade.h \
    tests/UserProfilPageTest.h \
    src/FileLoader.h \
    src/CommandSimulator.h \
    src/GameProcess.h \
    src/SelectableWidget.h \
    tests/GamepadMsgSerialTest.h
