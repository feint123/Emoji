CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(feintmaterialplugin)
TEMPLATE    = lib

HEADERS     = fbuttonplugin.h ftogglebuttonplugin.h fcircleplugin.h flabelplugin.h fcomboboxplugin.h flineeditplugin.h ftabwidgetplugin.h fcheckboxplugin.h fradiobuttonplugin.h ftexteditplugin.h fimageviewplugin.h feintmaterial.h
SOURCES     = fbuttonplugin.cpp ftogglebuttonplugin.cpp fcircleplugin.cpp flabelplugin.cpp fcomboboxplugin.cpp flineeditplugin.cpp ftabwidgetplugin.cpp fcheckboxplugin.cpp fradiobuttonplugin.cpp ftexteditplugin.cpp fimageviewplugin.cpp feintmaterial.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(flabel.pri)
include(ftabwidget.pri)
include(ftextedit.pri)
include(fimageview.pri)
include(ftogglebutton.pri)
include(fradiobutton.pri)
include(fbutton.pri)
include(fcircle.pri)
include(fcheckbox.pri)
include(fcombobox.pri)
include(flineedit.pri)
