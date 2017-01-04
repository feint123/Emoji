CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(feintplugin)
TEMPLATE    = lib

HEADERS     = fbuttonplugin.h ftooglebuttonplugin.h feint.h \

SOURCES     = fbuttonplugin.cpp ftooglebuttonplugin.cpp feint.cpp \

RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(ftooglebutton.pri)
include(fbutton.pri)

DISTFILES += \
    fcirclelabel.pri

