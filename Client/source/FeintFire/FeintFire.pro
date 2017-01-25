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

SOURCES += \
    domain/request/request.cpp \
    domain/response/artical.cpp \
    domain/response/articalinfo.cpp \
    domain/response/invitationcard.cpp \
    domain/response/uploadartical.cpp \
    artical/articalarea.cpp \
    artical/articalhot.cpp \
    factory/leaderfactory.cpp \
    factory/mainpartfactory.cpp \
    factory/menufactory.cpp \
    fileload/articaluploaddialog.cpp \
    listview/cardcell.cpp \
    listview/carditem.cpp \
    main/main.cpp \
    main/maincontent.cpp \
    main/mainpart.cpp \
    main/mainwindow.cpp \
    net/articalfactory.cpp \
    net/invitationfactory.cpp \
    plan/plan.cpp \
    plan/plancard.cpp \
    plan/plandialog.cpp \
    plan/planframe.cpp \
    user/logindialog.cpp \
    form.cpp \
    domain/request/normalloginrequest.cpp \
    user/settingdialog.cpp \
    domain/app/setting.cpp \
    user/settinghelper.cpp \
    factory/markdownfactory.cpp \
    control/menucontroller.cpp \
    control/settingcontroller.cpp \

HEADERS  += \
    domain/request/request.h \
    domain/response/artical.h \
    domain/response/articalinfo.h \
    domain/response/invitationcard.h \
    domain/response/uploadartical.h \
    artical/articalarea.h \
    artical/articalhot.h \
    factory/leaderfactory.h \
    factory/mainpartfactory.h \
    factory/menufactory.h \
    fileload/articaluploaddialog.h \
    listview/cardcell.h \
    listview/carditem.h \
    main/maincontent.h \
    main/mainpart.h \
    main/mainwindow.h \
    net/articalfactory.h \
    net/invitationfactory.h \
    plan/plan.h \
    plan/plancard.h \
    plan/plandialog.h \
    plan/planframe.h \
    user/logindialog.h \
    form.h \
    domain/request/normalloginrequest.h \
    user/settingdialog.h \
    domain/app/setting.h \
    user/settinghelper.h \
    factory/markdownfactory.h \
    control/menucontroller.h \
    control/settingcontroller.h \

FORMS    += \
    artical/articalarea.ui \
    fileload/articaluploaddialog.ui \
    listview/cardcell.ui \
    main/maincontent.ui \
    main/mainpart.ui \
    main/mainwindow.ui \
    plan/plancard.ui \
    plan/plandialog.ui \
    plan/planframe.ui \
    user/logindialog.ui \
    form.ui \
    user/settingdialog.ui


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

#plugin

macx: LIBS += -L$$PWD/../../../../../CTypeProject/QtProject/build-FButton-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintplugin

INCLUDEPATH += $$PWD/../../../../../CTypeProject/QtProject/FButton
DEPENDPATH += $$PWD/../../../../../CTypeProject/QtProject/FButton

DISTFILES +=

macx: LIBS += -L$$PWD/../../../../../CTypeProject/QtProject/build-FPlugin-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintmaterialplugin

INCLUDEPATH += $$PWD/../../../../../CTypeProject/QtProject/FPlugin
DEPENDPATH += $$PWD/../../../../../CTypeProject/QtProject/FPlugin
