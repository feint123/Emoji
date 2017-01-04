#include "documentutil.h"

#include <QTextEdit>
#include <QDebug>

DocumentUtil::DocumentUtil()
{

}

void DocumentUtil::remove(QTextEdit *edit, int i, int len)
{
    QString docStr=edit->toPlainText();
    docStr.remove(i,len);
    edit->setText(docStr);
    edit->selectAll();
    QTextCursor cursor=edit->textCursor();
    QTextBlockFormat format=cursor.blockFormat();
    format.setLineHeight(150,QTextBlockFormat::ProportionalHeight);
    cursor.setBlockFormat(format);
    cursor.clearSelection();
    cursor.setPosition(i);
    edit->setTextCursor(cursor);
}
