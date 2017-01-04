#ifndef HTMLBUILDER_H
#define HTMLBUILDER_H

#include <QObject>
#include <QString>






class HtmlBuilder:public QObject
{
    Q_OBJECT
public:
    HtmlBuilder();

    void setBody(const QString &value);

    QString getHtml() ;

private:
    QString body;
    QString header;
    QString html;
};

#endif // HTMLBUILDER_H
