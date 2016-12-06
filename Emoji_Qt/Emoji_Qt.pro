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
    file/configmanager.cpp

HEADERS  += view/mainwindow.h \
    graphic/imagerender.h \
    graphic/imagebasicdeal.h \
    file/imagefilemanager.h \
    graphic/emojitext.h \
    view/imagepart.h \
    view/filepart.h \
    view/emojilabel.h \
    file/configmanager.h \

FORMS    += mainwindow.ui \
    imagepart.ui \
    view/filepart.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/release/ -lfeint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/debug/ -lfeint
else:macx: LIBS += -L$$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../feint
DEPENDPATH += $$PWD/../feint

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/release/libfeint.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/debug/libfeint.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/release/feint.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/debug/feint.lib
else:macx: PRE_TARGETDEPS += $$PWD/../build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a
