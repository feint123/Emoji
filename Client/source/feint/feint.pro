#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T14:44:19
#
#-------------------------------------------------

QT       += widgets xml network
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
    pane/toolpart.ui \
    widget/view/listview.ui \
    pane/leader/backleader.ui \
    pane/markdown/markdown.ui \
    pane/markdown/dialog/markdownimagedialog.ui \
    pane/markdown/image/list/imageinfodialog.ui

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
    feint.h \
    pane/leader/backleader.h \
    pane/markdown/markdown.h \
    pane/markdown/markdownedit.h \
    pane/markdown/markdownhighlighter.h \
    graphic/screenhelper.h \
    widget/frame/fscaleframe.h \
    widget/frame/labelframe.h \
    widget/frame/labellabel.h \
    pane/markdown/html/markdowntohtml.h \
    pane/markdown/html/headerpraser.h \
    pane/markdown/html/htmlbuilder.h \
    pane/markdown/html/normalmarkdowntohtml.h \
    util/json/jsontoobject.h \
    fobject.h \
    util/json/objecttojson.h \
    pane/markdown/dialog/markdownimagedialog.h \
    util/net/networkhelper.h \
    util/graphic/effectutil.h \
    widget/frame/transframe.h \
    util/graphic/feintsetting.h \
    util/json/jsondata.h \
    util/graphic/innerdialogrect.h \
    pane/markdown/dialog/uploaddialog.h \
    pane/markdown/markdowncache.h \
    util/graphic/animationutil.h \
    widget/button/markdownimagebutton.h \
    widget/frame/imagepreview.h \
    pane/markdown/markdownmanager.h \
    pane/markdown/domain/markimage.h \
    pane/markdown/domain/markcontent.h \
    pane/markdown/highligherstyle.h \
    util/documentutil.h \
    util/fileutil.h \
    widget/view/gridview.h \
    util/qvariantutil.h \
    pane/markdown/domain/markimagesimple.h \
    pane/menu/basemenu.h \
    action/imagebtnaction.h \
    util/dialogshowutil.h \
    pane/markdown/image/imagedialog.h \
    pane/markdown/image/imagecontrol.h \
    pane/markdown/image/imageframe.h \
    widget/frame/shorttip.h \
    pane/image/domain/image.h \
    action/editaction.h \
    pane/markdown/image/imagepreviewdialog.h \
    pane/markdown/image/list/imageitem.h \
    pane/markdown/image/list/imageitemview.h \
    widget/view/gridviewbeauti.h \
    pane/markdown/image/list/imageinfodialog.h \
    util/graphic/imageutil.h \
    pane/markdown/markdownparahighlighter.h \
    widget/view/listviewbeauti.h \
    pane/markdown/dialog/list/quicklistitem.h \
    pane/markdown/dialog/list/quicklistitemview.h \
    widget/basewidget.h \
    widget/view/abstructview.h

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
    pane/leader/backleader.cpp \
    pane/markdown/markdown.cpp \
    pane/markdown/markdownedit.cpp \
    pane/markdown/markdownhighlighter.cpp \
    graphic/screenhelper.cpp \
    widget/frame/fscaleframe.cpp \
    widget/frame/labelframe.cpp \
    widget/frame/labellabel.cpp \
    pane/markdown/html/markdowntohtml.cpp \
    pane/markdown/html/headerpraser.cpp \
    pane/markdown/html/htmlbuilder.cpp \
    pane/markdown/html/normalmarkdowntohtml.cpp \
    util/json/jsontoobject.cpp \
    fobject.cpp \
    util/json/objecttojson.cpp \
    pane/markdown/dialog/markdownimagedialog.cpp \
    util/net/networkhelper.cpp \
    util/graphic/effectutil.cpp \
    widget/frame/transframe.cpp \
    util/graphic/feintsetting.cpp \
    util/json/jsondata.cpp \
    util/graphic/innerdialogrect.cpp \
    pane/markdown/dialog/uploaddialog.cpp \
    pane/markdown/markdowncache.cpp \
    util/graphic/animationutil.cpp \
    widget/button/markdownimagebutton.cpp \
    widget/frame/imagepreview.cpp \
    pane/markdown/markdownmanager.cpp \
    pane/markdown/domain/markimage.cpp \
    pane/markdown/domain/markcontent.cpp \
    pane/markdown/highligherstyle.cpp \
    util/documentutil.cpp \
    util/fileutil.cpp \
    widget/view/gridview.cpp \
    util/qvariantutil.cpp \
    pane/markdown/domain/markimagesimple.cpp \
    pane/menu/basemenu.cpp \
    action/imagebtnaction.cpp \
    util/dialogshowutil.cpp \
    pane/markdown/image/imagedialog.cpp \
    pane/markdown/image/imagecontrol.cpp \
    pane/markdown/image/imageframe.cpp \
    widget/frame/shorttip.cpp \
    pane/image/domain/image.cpp \
    action/editaction.cpp \
    pane/markdown/image/imagepreviewdialog.cpp \
    pane/markdown/image/list/imageitem.cpp \
    pane/markdown/image/list/imageitemview.cpp \
    widget/view/gridviewbeauti.cpp \
    pane/markdown/image/list/imageinfodialog.cpp \
    util/graphic/imageutil.cpp \
    pane/markdown/markdownparahighlighter.cpp \
    widget/view/listviewbeauti.cpp \
    pane/markdown/dialog/list/quicklistitem.cpp \
    pane/markdown/dialog/list/quicklistitemview.cpp \
    widget/basewidget.cpp \
    widget/view/abstructview.cpp


macx: LIBS += -L$$PWD/../../../../../CTypeProject/QtProject/build-FButton-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintplugin

INCLUDEPATH += $$PWD/../../../../../CTypeProject/QtProject/FButton
DEPENDPATH += $$PWD/../../../../../CTypeProject/QtProject/FButton

DISTFILES += \
    back.png \
    Category.png \
    header.png \
    set.png

macx: LIBS += -L$$PWD/../../../../../CTypeProject/QtProject/build-FPlugin-Desktop_Qt_5_7_0_clang_64bit-Release/ -lfeintmaterialplugin

INCLUDEPATH += $$PWD/../../../../../CTypeProject/QtProject/FPlugin
DEPENDPATH += $$PWD/../../../../../CTypeProject/QtProject/FPlugin
