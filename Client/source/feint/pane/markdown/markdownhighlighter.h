#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>



class MarkDownHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    enum Type{
        HEADER,
        BOLD,
        DEVIDE,
        ITALIC,
        ORDERLIST,
        UNORDERLIST,
        CODEBLOCK,
        QUOTEBLOCK,
        CODE,
        DELETE,
        IMG,
    };

    MarkDownHighlighter(QTextDocument *parent=0);
    QHash<Type, QColor> getTypeColor() const;
    void setTypeColor(const QHash<Type, QColor> &value);
    void createTypeFormat();

public slots:
    void setFontBaseSize(int value);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    QTextDocument *doc;

    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat headerFormat;
    QTextCharFormat devideFormat;
    QTextCharFormat boldFormat;
    QTextCharFormat italicFormat;
    QTextCharFormat boldItalicFormat;
    QTextCharFormat orderListFormat;
    QTextCharFormat unorderListFormat;
    QTextCharFormat codeBlockFormat;
    QTextCharFormat quoteBlockFormat;
    QTextCharFormat codeFormat;
    QTextCharFormat imgFormat;
    QTextCharFormat deleteFormat;

    QHash<Type,QColor> typeColor;

    HighlightingRule rule;
    void initTypeColor();

    void initPartFormat();
    void initHeaderFormat();



    int fontBaseSize=13;

};

#endif // MARKDOWNHIGHLIGHTER_H
