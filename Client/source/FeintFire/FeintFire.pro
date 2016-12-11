#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T23:30:57
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FeintFire
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainpart.cpp \
    maincontent.cpp \
    domain/articalcard.cpp \
    carditem.cpp \
    cardcell.cpp \
    net/invitationfactory.cpp \
    articalarea.cpp \
    net/articalfactory.cpp

HEADERS  += mainwindow.h \
    mainpart.h \
    maincontent.h \
    domain/articalcard.h \
    carditem.h \
    cardcell.h \
    net/invitationfactory.h \
    articalarea.h \
    net/articalfactory.h

FORMS    += mainwindow.ui \
    mainpart.ui \
    maincontent.ui \
    cardcell.ui \
    articalarea.ui

macx: LIBS += -L$$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../feint
DEPENDPATH += $$PWD/../feint

macx: PRE_TARGETDEPS += $$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a
