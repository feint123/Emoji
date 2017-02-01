#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T12:41:37
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FeintEdit
TEMPLATE = app


ICON = resource/feint.icns

SOURCES += \
    action/notebookaction.cpp \
    controller/notecontroller.cpp \
    controller/noteeditcontroller.cpp \
    controller/settingcontroller.cpp \
    domain/notebook.cpp \
    domain/notetip.cpp \
    domain/setting.cpp \
    factory/markdownfactory.cpp \
    factory/menulinefactory.cpp \
    factory/notecontrolfactory.cpp \
    plug/settingdialog.cpp \
    util/editloader.cpp \
    util/notebooklistloader.cpp \
    util/settinghelper.cpp \
    view/note/controlfloatbutton.cpp \
    view/note/noteitem.cpp \
    view/note/noteitemview.cpp \
    view/note/notelist.cpp \
    view/notebook/notebookdialog.cpp \
    view/notebook/notebookitem.cpp \
    view/notebook/notebookitemview.cpp \
    view/markdownplace.cpp \
    view/markdowntitle.cpp \
    view/menuline.cpp \
    view/notebooks.cpp \
    view/tipdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    view/note/notes.cpp \
    action/noteaction.cpp \
    action/noteeditaction.cpp \
    action/noteimageaction.cpp \
    view/notebook/notebookstarter.cpp \
    plug/filecopydialog.cpp \
    view/note/noteheader.cpp \
    view/notebook/list/notebooknamedialog.cpp \
    view/notebook/list/notebooknameitem.cpp \
    util/noteutil.cpp \
    domain/notein.cpp \
    util/notedatautil.cpp \
    util/timermanager.cpp \
    domain/timertag.cpp \
    domain/appcolor.cpp \
    util/appcolorhelper.cpp \
    domain/highlighter.cpp \
    util/highlighterhelper.cpp \
    util/plughelper.cpp \
    plug/highlighterstyle.cpp \
    view/recircle/recircleitem.cpp \
    view/recircle/recircleitemview.cpp \
    view/recircle/recircle.cpp \
    domain/recirclepage.cpp \
    plug/appstatic.cpp \
    view/tool/notebooktool.cpp \
    factory/toolfactory.cpp \
    view/tool/notetool.cpp \
    view/tool/basetool.cpp \
    view/recircle/recircleheader.cpp \
    domain/appmessage.cpp \
    domain/lastedit.cpp \
    view/recircle/lastedititem.cpp \
    view/recircle/lastedititemview.cpp \
    util/screenfit.cpp \
    domain/wordstatic.cpp \
    action/markdownquick.cpp \
    view/feintbutton.cpp \
    domain/word.cpp \
    util/wordhelper.cpp \
    view/abstracttabbar.cpp \
    view/pulldownlist/pulldownlist.cpp \
    view/pulldownlist/listframe.cpp \
    view/pulldownlist/fwidget.cpp \
    view/pulldownlist/pulldownlistitem.cpp \
    view/pulldownlist/widgetcreator.cpp \
    test/pulldowntest.cpp \
    test/flabelwidget.cpp \
    view/note/markpull/markpulldown.cpp \
    view/note/markpull/markitem.cpp \
    view/note/markpull/markfactory.cpp \
    view/note/markpull/markdownhotkey.cpp

HEADERS  += \
    action/notebookaction.h \
    controller/notecontroller.h \
    controller/noteeditcontroller.h \
    controller/settingcontroller.h \
    domain/notebook.h \
    domain/notetip.h \
    domain/setting.h \
    factory/markdownfactory.h \
    factory/menulinefactory.h \
    factory/notecontrolfactory.h \
    plug/settingdialog.h \
    util/editloader.h \
    util/notebooklistloader.h \
    util/settinghelper.h \
    view/note/controlfloatbutton.h \
    view/note/noteitem.h \
    view/note/noteitemview.h \
    view/note/notelist.h \
    view/notebook/notebookdialog.h \
    view/notebook/notebookitem.h \
    view/notebook/notebookitemview.h \
    view/markdownplace.h \
    view/markdowntitle.h \
    view/menuline.h \
    view/notebooks.h \
    view/tipdialog.h \
    mainwindow.h \
    view/note/notes.h \
    action/noteaction.h \
    action/noteeditaction.h \
    action/noteimageaction.h \
    view/notebook/notebookstarter.h \
    plug/filecopydialog.h \
    view/note/noteheader.h \
    view/notebook/list/notebooknamedialog.h \
    view/notebook/list/notebooknameitem.h \
    util/noteutil.h \
    domain/notein.h \
    util/notedatautil.h \
    util/timermanager.h \
    domain/timertag.h \
    domain/appcolor.h \
    util/appcolorhelper.h \
    domain/highlighter.h \
    util/highlighterhelper.h \
    util/plughelper.h \
    plug/highlighterstyle.h \
    view/recircle/recircleitem.h \
    view/recircle/recircleitemview.h \
    view/recircle/recircle.h \
    domain/recirclepage.h \
    plug/appstatic.h \
    view/tool/notebooktool.h \
    factory/toolfactory.h \
    view/tool/notetool.h \
    view/tool/basetool.h \
    view/recircle/recircleheader.h \
    domain/appmessage.h \
    domain/lastedit.h \
    view/recircle/lastedititem.h \
    view/recircle/lastedititemview.h \
    util/screenfit.h \
    domain/wordstatic.h \
    action/markdownquick.h \
    view/feintbutton.h \
    domain/word.h \
    util/wordhelper.h \
    view/abstracttabbar.h \
    view/pulldownlist/pulldownlist.h \
    view/pulldownlist/listframe.h \
    view/pulldownlist/fwidget.h \
    view/pulldownlist/pulldownlistitem.h \
    view/pulldownlist/widgetcreator.h \
    test/pulldowntest.h \
    test/flabelwidget.h \
    view/note/markpull/markpulldown.h \
    view/note/markpull/markitem.h \
    view/note/markpull/markfactory.h \
    view/note/markpull/markdownhotkey.h

macx: LIBS += -L$$PWD/../build-FButton-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintplugin

INCLUDEPATH += $$PWD/../FButton
DEPENDPATH += $$PWD/../FButton

macx: LIBS += -L$$PWD/../build-FPlugin-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintmaterialplugin

INCLUDEPATH += $$PWD/../FPlugin
DEPENDPATH += $$PWD/../FPlugin

macx: LIBS += -L$$PWD/../../../Desktop/Emoji/build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/ -lfeint

INCLUDEPATH += $$PWD/../../../Desktop/Emoji/Client/source/feint
DEPENDPATH += $$PWD/../../../Desktop/Emoji/Client/source/feint

macx: PRE_TARGETDEPS += $$PWD/../../../Desktop/Emoji/build-feint-Desktop_Qt_5_7_0_clang_64bit-Debug/libfeint.a

RESOURCES += \
    resource/resource.qrc

FORMS += \
    plug/settingdialog.ui \
    view/note/noteitemview.ui \
    view/notebook/notebookdialog.ui \
    view/markdowntitle.ui \
    view/tool/notebooktool.ui \
    view/tool/notetool.ui \
    view/recircle/recircleheader.ui

DISTFILES += \
    setting.json \
    resource/recircle.png


