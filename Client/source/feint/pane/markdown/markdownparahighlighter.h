#ifndef MARKDOWNPARAHIGHLIGHTER_H
#define MARKDOWNPARAHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QTextEdit>



class MarkdownParaHighlighter:public QObject
{
    Q_OBJECT
public:
    MarkdownParaHighlighter(QTextEdit *doc=0);

private slots:
    void onDocChanged(QString text);
    void onTextChanged();
signals:
    void plainTextChanged(QString);

private:
    QTextEdit *doc;
    QString plainText="";

protected:
    void setFormat(QTextCharFormat format,int index,int length);

};

#endif // MARKDOWNPARAHIGHLIGHTER_H
