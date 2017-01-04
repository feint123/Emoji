#ifndef DOCUMENTUTIL_H
#define DOCUMENTUTIL_H

#include <QTextDocument>
#include <QTextEdit>



class DocumentUtil
{
public:
    DocumentUtil();
    static void remove(QTextEdit *edit,int i,int len);
};

#endif // DOCUMENTUTIL_H
