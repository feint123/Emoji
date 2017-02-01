#include "markdownfactory.h"

#include <util/appcolorhelper.h>
#include <util/settinghelper.h>

#include <pane/markdown/highligherstyle.h>
#include <pane/markdown/markdownparahighlighter.h>

#include <plug/highlighterstyle.h>

#include <QFileSystemWatcher>

#include <action/markdownquick.h>

#include <domain/wordstatic.h>

MarkDownFactory::MarkDownFactory()
{

}

MarkDownEdit *MarkDownFactory::create(QWidget *parent)
{

        Setting *setting=SettingHelper::setting();
        AppColor *color=AppColorHelper::loadColor();
        MarkDownEdit *edit=new MarkDownEdit(parent);

        edit->setBackground(color->editorBg());
        edit->setColor(color->colorMid());
        edit->setScrollHandle(color->scrollHandle());
        edit->setScrollPage(color->scrollPage());
        edit->setHigh(HighlighterStyle::style);
        edit->setTheme();

        edit->setDefaultPath(setting->workspacing());
        QFont font(setting->fontFamily());
        font.setPointSize(setting->fontSize());

        MarkDownQuick *quick=MarkDownQuick::getInstance(edit);
        quick->setEdit(edit);
        quick->createActions();

        QMenu *qM=new QMenu();
        qM->addActions(quick->getActionList());
        edit->addActions(quick->getActionList());
        edit->setQuickMenu(qM);
        edit->setQuickString(WordStatic ::markQuick);

        quick->setBaseSize(setting->fontSize());

        QObject::connect(quick,SIGNAL(baseSizeChanged(int)),
                edit->getLighter(),SLOT(setFontBaseSize(int)));

  //      MarkdownParaHighlighter *para=new MarkdownParaHighlighter(edit);

        edit->setFont(font);
        edit->refreshFormat();
        return edit;
}

