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
    pane/normaltoolpane.cpp \
    widget/label/colorlabel.cpp \
    util/xml/xmlanalysis.cpp \
    domain/setting/textsetting.cpp \
    util/xml/settingtextanalysis.cpp \
    pane/showpane.cpp \
    widget/view/listview.cpp \
    widget/view/listitem.cpp

HEADERS += feint.h \
    graphic/emojitext.h \
    pane/toolpart.h \
    pane/normaltoolpane.h \
    widget/label/colorlabel.h \
    util/xml/xmlanalysis.h \
    domain/setting/textsetting.h \
    util/xml/settingtextanalysis.h \
    pane/showpane.h \
    widget/view/listview.h \
    widget/view/listitem.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    pane/toolpart.ui \
    pane/normaltoolpane.ui \
    pane/showpane.ui
