#ifndef MARKDOWNFACTORY_H
#define MARKDOWNFACTORY_H

#include <util/graphic/feintsetting.h>

#include <pane/markdown/markdown.h>



class MarkDownFactory:public QObject
{
    Q_OBJECT
public:
    MarkDownFactory();
    static MarkDown* create(FeintSetting::STYLE style);
};

#endif // MARKDOWNFACTORY_H
