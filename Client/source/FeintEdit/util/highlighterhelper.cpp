#include "highlighterhelper.h"
#include "plughelper.h"
#include <QCoreApplication>

HighlighterHelper::HighlighterHelper()
{

}

Highlighter *HighlighterHelper::loadHighlighter()
{
    return PlugHelper::loadPlug<Highlighter>(tr("%1/%2")
                                             .arg(QCoreApplication::applicationDirPath())
                                             .arg("highlighter.json").toUtf8());
}

void HighlighterHelper::saveHighlighter(Highlighter *high)
{
    PlugHelper::savePlug(tr("%1/%2")
                         .arg(QCoreApplication::applicationDirPath())
                         .arg("highlighter.json").toUtf8(),high);
}

bool HighlighterHelper::hasHighlighter()
{
    return PlugHelper::hasPlug(tr("%1/%2")
                               .arg(QCoreApplication::applicationDirPath())
                               .arg("highlighter.json").toUtf8());
}
