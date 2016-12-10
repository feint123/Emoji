#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T14:44:19
#
#-------------------------------------------------

QT       += widgets xml

TARGET = feint
TEMPLATE = lib
CONFIG += staticlib

RESOURCES += \
    icons.qrc

FORMS += \
    pane/menu/feintmenu.ui \
    pane/leader/searchleader.ui

HEADERS += \
    pane/menu/feintmenu.h \
    widget/button/menubutton.h \
    pane/leader/searchleader.h

SOURCES += \
    pane/menu/feintmenu.cpp \
    widget/button/menubutton.cpp \
    pane/leader/searchleader.cpp


