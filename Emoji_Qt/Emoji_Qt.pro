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
    view/toolpart.cpp

HEADERS  += view/mainwindow.h \
    graphic/imagerender.h \
    graphic/imagebasicdeal.h \
    file/imagefilemanager.h \
    graphic/emojitext.h \
    view/imagepart.h \
    view/filepart.h \
    view/toolpart.h

FORMS    += mainwindow.ui \
    imagepart.ui \
    view/filepart.ui \
    view/toolpart.ui
