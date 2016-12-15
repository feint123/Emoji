#include "markdownhighlighter.h"

MarkDownHighlighter::MarkDownHighlighter(QTextDocument *parent):
    QSyntaxHighlighter(parent)
{
    initTypeColor();





}

void MarkDownHighlighter::highlightBlock(const QString &text)
{
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
    headerFormat.setFontPointSize(16);
    //设置字体颜色
    headerFormat.setForeground(typeColor[HEADER]);
    rule.format=headerFormat;
    rule.pattern=QRegExp("^#{1,6}.*$");
    highlightingRules.append(rule);

    orderListFormat.setForeground(typeColor[ORDERLIST]);
    rule.format=orderListFormat;
    rule.pattern=QRegExp("^\\t*[1-9]+\\.\\s.*");
    highlightingRules.append(rule);

    unorderListFormat.setForeground(typeColor[UNORDERLIST]);
    rule.format=unorderListFormat;
    rule.pattern=QRegExp("^\\t*\\-\\s.*");
    highlightingRules.append(rule);

    devideFormat.setForeground(typeColor[DEVIDE]);
    rule.format=devideFormat;
    rule.pattern=QRegExp("^-{4}$");
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
    rule.pattern=QRegExp("^`.*`$");
    highlightingRules.append(rule);
}


void MarkDownHighlighter::initPartFormat()
{
    italicFormat.setFontItalic(true);
    italicFormat.setForeground(typeColor[ITALIC]);
    rule.format=italicFormat;
    rule.pattern=QRegExp("\\*.*\\*");
    highlightingRules.append(rule);

    boldFormat.setFontWeight(QFont::Bold);
    boldFormat.setForeground(typeColor[BOLD]);
    rule.format=boldFormat;
    rule.pattern=QRegExp("\\*\\*.*\\*\\*");
    highlightingRules.append(rule);

    boldItalicFormat.setFontWeight(QFont::Bold);
    boldItalicFormat.setFontItalic(true);
    boldItalicFormat.setForeground(typeColor[ITALIC]);
    rule.format=boldItalicFormat;
    rule.pattern=QRegExp("^(\\*\\*.*)\\*.*\\*(.*\\*\\*)$");
    highlightingRules.append(rule);
}

QHash<MarkDownHighlighter::Type, QColor> MarkDownHighlighter::getTypeColor() const
{
    return typeColor;
}

void MarkDownHighlighter::setTypeColor(const QHash<Type, QColor> &value)
{
    typeColor = value;
}
