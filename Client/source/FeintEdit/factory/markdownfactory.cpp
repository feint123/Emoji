#include "markdownfactory.h"

#include <util/settinghelper.h>

#include <pane/markdown/markdownparahighlighter.h>
#include <pane/markdown/markdownquick.h>

MarkDownFactory::MarkDownFactory()
{

}

MarkDownEdit *MarkDownFactory::create(QWidget *parent)
{
        Setting *setting=SettingHelper::setting();
        MarkDownEdit *edit=new MarkDownEdit(parent);
        edit->setTheme(MarkDownEdit::DARK);
        edit->setDefaultPath(setting->workspacing());
        QFont font(setting->fontFamily());
        font.setPointSize(setting->fontSize());

        MarkDownQuick *quick=new MarkDownQuick(edit);
        quick->setBaseSize(setting->fontSize());
        QObject::connect(quick,SIGNAL(baseSizeChanged(int)),
                edit->getLighter(),SLOT(setFontBaseSize(int)));

  //      MarkdownParaHighlighter *para=new MarkdownParaHighlighter(edit);

        edit->setFont(font);
        edit->refreshFormat();
        return edit;
}

