#include "markdownparahighlighter.h"

#include <qtextcursor.h>
#include <QTextBlock>
#include <QDebug>
MarkdownParaHighlighter::MarkdownParaHighlighter(QTextEdit *doc)
{
    this->doc=doc;
    connect(doc,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
    connect(this,SIGNAL(plainTextChanged(QString)),this,SLOT(onDocChanged(QString)));
}

void MarkdownParaHighlighter::onDocChanged(QString text)
{
    QRegExp reg("\n{2,}\\+");
    int index=reg.indexIn(doc->toPlainText());
    QTextCursor cursor=doc->textCursor();
    int start=index+reg.matchedLength()-1;
    int currentPos=start;
    QTextCharFormat format;
    format.setForeground(Qt::yellow);
    while(index>=0)
    {
        cursor.setPosition(start);

        if(cursor.block().text().length()==0)
        {

            index=reg.indexIn(doc->toPlainText(),currentPos);
            continue;
        }

        bool move=cursor.movePosition(QTextCursor::NextBlock);

        currentPos=cursor.anchor();

        if(!move)
            break;
        else
        {
            qDebug()<<text.mid(start,currentPos-start+1);
            setFormat(format,start,currentPos-start+1);
            start=currentPos;
        }
    }
}

void MarkdownParaHighlighter::onTextChanged()
{

    if(plainText==doc->toPlainText())
        return;
    plainText=doc->toPlainText();
    emit plainTextChanged(plainText);
}

void MarkdownParaHighlighter::setFormat(QTextCharFormat format, int index, int length)
{
    int pos=doc->textCursor().anchor();
    QTextCursor cursor=doc->textCursor();
    QTextCharFormat _format=cursor.charFormat();
    cursor.setPosition(index);
    cursor.setPosition(index+length,QTextCursor::KeepAnchor);
    cursor.setCharFormat(format);
    cursor.setPosition(pos);
    doc->setTextCursor(cursor);
    cursor.setCharFormat(_format);
    doc->setTextCursor(cursor);
}



