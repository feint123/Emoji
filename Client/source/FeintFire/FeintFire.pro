#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T23:30:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FeintFire
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

macx: LIBS += -L$$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../feint
DEPENDPATH += $$PWD/../feint

macx: PRE_TARGETDEPS += $$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a
