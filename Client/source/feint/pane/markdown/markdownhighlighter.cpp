#include "markdownhighlighter.h"
#include <QDebug>
MarkDownHighlighter::MarkDownHighlighter(QTextDocument *parent):
    QSyntaxHighlighter(parent)
{
    this->doc=parent;
    initTypeColor();
}

void MarkDownHighlighter::highlightBlock(const QString &text)
{
    createTypeFormat();
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);

}

void MarkDownHighlighter::initTypeColor()
{
    typeColor[HEADER]=Qt::darkYellow;
    typeColor[BOLD]=Qt::gray;
    typeColor[ORDERLIST]=QColor("#6d2c82");
    typeColor[UNORDERLIST]=QColor("#6d2c82");
    typeColor[DEVIDE]=QColor("#e82121");
    typeColor[CODEBLOCK]=QColor("#368afc");
    typeColor[CODE]=QColor("#38ad52");
    typeColor[QUOTEBLOCK]=QColor("#404244");
    typeColor[ITALIC]=QColor("#ccc");

}

void MarkDownHighlighter::createTypeFormat()
{
    /**
     *  语法高量的包含关系与，添加约束条件的顺序有关
     *
     */
    highlightingRules.clear();

    initHeaderFormat();

    orderListFormat.setForeground(typeColor[ORDERLIST]);
    rule.format=orderListFormat;
    rule.pattern=QRegExp("^\\t*[0-9]+\\.\\s.*");
    highlightingRules.append(rule);

    unorderListFormat.setForeground(typeColor[UNORDERLIST]);
    rule.format=unorderListFormat;
    rule.pattern=QRegExp("^\\t*\\-\\s.*");
    highlightingRules.append(rule);

    devideFormat.setForeground(typeColor[DEVIDE]);
    rule.format=devideFormat;
    rule.pattern=QRegExp("^-{4,}$");
    highlightingRules.append(rule);

    initPartFormat();

    codeBlockFormat.setForeground(typeColor[CODEBLOCK]);
    rule.format=codeBlockFormat;
    rule.pattern=QRegExp("^''.*$");
    highlightingRules.append(rule);

    quoteBlockFormat.setForeground(typeColor[QUOTEBLOCK]);
    quoteBlockFormat.setFontWeight(QFont::Bold);
    rule.format=quoteBlockFormat;
    rule.pattern=QRegExp("^>.*$");
    highlightingRules.append(rule);

    codeFormat.setForeground(typeColor[CODE]);
    rule.format=codeFormat;
    rule.pattern=QRegExp("`.*`");
    highlightingRules.append(rule);

    imgFormat.setForeground(typeColor[IMG]);
    rule.format=imgFormat;
    rule.pattern=QRegExp("\\!\\[[0-9]+\\]");
    highlightingRules.append(rule);


}


void MarkDownHighlighter::initPartFormat()
{
    italicFormat.setFontItalic(true);
    italicFormat.setForeground(typeColor[ITALIC]);
    rule.format=italicFormat;
    rule.pattern=QRegExp("\\_((?!\\_).)*\\_");
    highlightingRules.append(rule);

    boldFormat.setFontWeight(QFont::Bold);
    boldFormat.setForeground(typeColor[BOLD]);
    rule.format=boldFormat;
    rule.pattern=QRegExp("\\*\\*((?!\\*).)*\\*\\*");
    highlightingRules.append(rule);

}

void MarkDownHighlighter::initHeaderFormat()
{
    for(int i=1;i<=6;i++)
    {
        headerFormat.setForeground(typeColor[HEADER]);
        headerFormat.setFontPointSize(fontBaseSize*(2-1.8*(float)i/10.0));
        rule.format=headerFormat;
        rule.pattern=QRegExp(tr("^#{%1}.*$").arg(i));
        highlightingRules.append(rule);
    }
}

void MarkDownHighlighter::setFontBaseSize(int value)
{
    fontBaseSize = value;
}

QHash<MarkDownHighlighter::Type, QColor> MarkDownHighlighter::getTypeColor() const
{
    return typeColor;
}

void MarkDownHighlighter::setTypeColor(const QHash<Type, QColor> &value)
{
    typeColor = value;
}
