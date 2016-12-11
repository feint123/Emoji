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
    pane/leader/searchleader.ui \
    pane/normaltoolpane.ui \
    pane/showpane.ui \
    pane/toolpart.ui

HEADERS += \
    pane/menu/feintmenu.h \
    widget/button/menubutton.h \
    pane/leader/searchleader.h \
    domain/setting/textsetting.h \
    graphic/emojitext.h \
    pane/normaltoolpane.h \
    pane/showpane.h \
    pane/toolpart.h \
    util/xml/settingtextanalysis.h \
    util/xml/xmlanalysis.h \
    widget/label/colorlabel.h \
    widget/view/listitem.h \
    widget/view/listview.h \
    feint.h

SOURCES += \
    pane/menu/feintmenu.cpp \
    widget/button/menubutton.cpp \
    pane/leader/searchleader.cpp \
    domain/setting/textsetting.cpp \
    graphic/emojitext.cpp \
    pane/normaltoolpane.cpp \
    pane/showpane.cpp \
    pane/toolpart.cpp \
    util/xml/settingtextanalysis.cpp \
    util/xml/xmlanalysis.cpp \
    widget/label/colorlabel.cpp \
    widget/view/listitem.cpp \
    widget/view/listview.cpp \
    feint.cpp


