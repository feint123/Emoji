#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T19:02:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Emoji_Qt
TEMPLATE = app


SOURCES += main.cpp\
    view/mainwindow.cpp \
    graphic/imagerender.cpp \
    graphic/imagebasicdeal.cpp \
    file/imagefilemanager.cpp \
    graphic/emojitext.cpp \
    view/imagepart.cpp \
    view/filepart.cpp \
    view/emojilabel.cpp \
    file/configmanager.cpp \
    view/colorlabel.cpp

HEADERS  += view/mainwindow.h \
    graphic/imagerender.h \
    graphic/imagebasicdeal.h \
    file/imagefilemanager.h \
    graphic/emojitext.h \
    view/imagepart.h \
    view/filepart.h \
    view/emojilabel.h \
    file/configmanager.h \
    view/colorlabel.h\

FORMS    += mainwindow.ui \
    imagepart.ui \
    view/filepart.ui






macx|win32: LIBS += -L$$PWD/../../../CTypeProject/QtProject/build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../../../CTypeProject/QtProject/feint
DEPENDPATH += $$PWD/../../../CTypeProject/QtProject/feint

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../CTypeProject/QtProject/build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/feint.lib
else:macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../../CTypeProject/QtProject/build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a
