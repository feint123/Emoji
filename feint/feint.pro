#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T14:44:19
#
#-------------------------------------------------

QT       += widgets xml

TARGET = feint
TEMPLATE = lib
CONFIG += staticlib

SOURCES += feint.cpp \
    graphic/emojitext.cpp \
    pane/toolpart.cpp \
    pane/normaltoolpane.cpp

HEADERS += feint.h \
    graphic/emojitext.h \
    pane/toolpart.h \
    pane/normaltoolpane.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    pane/toolpart.ui \
    pane/normaltoolpane.ui
