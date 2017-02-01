#ifndef HIGHLIGHTERHELPER_H
#define HIGHLIGHTERHELPER_H

#include <domain/highlighter.h>



class HighlighterHelper:public QObject
{
public:
    HighlighterHelper();
    static Highlighter *loadHighlighter();

    static void saveHighlighter(Highlighter *high);

    static bool hasHighlighter();

};

#endif // HIGHLIGHTERHELPER_H
