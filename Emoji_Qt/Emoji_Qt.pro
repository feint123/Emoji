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
    graphic/imagebasicdeal.cpp \
    file/imagefilemanager.cpp \
    graphic/emojitext.cpp

HEADERS  += view/mainwindow.h \
    graphic/imagerender.h \
    graphic/imagebasicdeal.h \
    graphic/imagebasicdeal.h \
    file/imagefilemanager.h \
    graphic/emojitext.h

FORMS    += mainwindow.ui
