#ifndef MARKDOWNTOHTML_H
#define MARKDOWNTOHTML_H

#include "htmlbuilder.h"

#include <QObject>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

 struct HtmlRule{
    QString label;
    QRegExp pattern;
    int markLength;
    int type;
    int endType=0;
};

class MarkDownToHtml:QObject
{
    Q_OBJECT
public:
    MarkDownToHtml();
    QVector<HtmlRule> getHtmlRules() const;

    QHash<QString, QString> getLabelHash() const;



    QStringList getNornalLabelList() const;

private:
    QVector<HtmlRule> htmlRules;
    QHash<QString, QString> labelHash;
    QStringList nornalLabelList;
    void initHtmlReg();
    void createLabel();

};

#endif // MARKDOWNTOHTML_H
