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
    net/articalfactory.cpp \
    net/networkhelper.cpp \
    domain/artical.cpp \
    domain/articalinfo.cpp \
    form.cpp \
    fileload/articaluploaddialog.cpp

HEADERS  += mainwindow.h \
    mainpart.h \
    maincontent.h \
    domain/articalcard.h \
    carditem.h \
    cardcell.h \
    net/invitationfactory.h \
    articalarea.h \
    net/articalfactory.h \
    net/networkhelper.h \
    domain/artical.h \
    domain/articalinfo.h \
    form.h \
    fileload/articaluploaddialog.h

FORMS    += mainwindow.ui \
    mainpart.ui \
    maincontent.ui \
    cardcell.ui \
    articalarea.ui \
    form.ui \
    fileload/articaluploaddialog.ui


macx: LIBS += -L$$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../feint
DEPENDPATH += $$PWD/../feint

macx: PRE_TARGETDEPS += $$PWD/../../../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a

RESOURCES += \
    resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/release/ -lfeint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/debug/ -lfeint

INCLUDEPATH += $$PWD/../feint
DEPENDPATH += $$PWD/../feint

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/release/libfeint.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/debug/libfeint.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/release/feint.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_MSVC2013_64bit-Debug/debug/feint.lib
