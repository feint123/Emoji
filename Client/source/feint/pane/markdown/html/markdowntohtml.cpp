#include "htmlbuilder.h"
#include "markdowntohtml.h"
#include <QDebug>
#include <QTextDocument>
MarkDownToHtml::MarkDownToHtml()
{
    createLabel();
    initHtmlReg();
}


QVector<HtmlRule> MarkDownToHtml::getHtmlRules() const
{
    return htmlRules;
}

QHash<QString, QString> MarkDownToHtml::getLabelHash() const
{
    return labelHash;
}

QStringList MarkDownToHtml::getNornalLabelList() const
{
    return nornalLabelList;
}

void MarkDownToHtml::initHtmlReg()
{
    HtmlRule rule;
    /*设置head标签*/
    rule.label=tr("<h1>");
    rule.pattern=QRegExp("^#{1}[^#].*$");
    rule.markLength=1;
    rule.type=2;
    htmlRules.append(rule);


    rule.label=tr("<h2>");
    rule.pattern=QRegExp("^#{2}[^#].*$");
    rule.markLength=2;
    rule.type=2;
    htmlRules.append(rule);


    rule.label=tr("<h3>");
    rule.pattern=QRegExp("^#{3}[^#].*$");
    rule.markLength=3;
    rule.type=2;
    htmlRules.append(rule);


    rule.label=tr("<h4>");
    rule.pattern=QRegExp("^#{4}[^#].*$");
    rule.markLength=4;
    rule.type=2;
    htmlRules.append(rule);

    rule.label=tr("<code>");
    rule.pattern=QRegExp("^>.*$");
    rule.markLength=1;
    rule.type=2;
    htmlRules.append(rule);

    rule.label=tr("<hr>");
    rule.pattern=QRegExp("^-{4}$");
    rule.markLength=4;
    rule.type=1;
    htmlRules.append(rule);

    rule.label=tr("<ol>");
    rule.pattern=QRegExp("^\\t*[1-9]+\\.\\s.*");
  //  rule.markLength=;
    rule.type=3;
    htmlRules.append(rule);

    rule.label=tr("<ul>");
    rule.pattern=QRegExp("^\\t*\\-\\s.*");
  //  rule.markLength=;
    rule.type=3;
    htmlRules.append(rule);

    rule.label=tr("<strong>");
    rule.pattern=QRegExp("\\*\\*.*\\*\\*");
    rule.markLength=2;
    rule.type=2;
    rule.endType=2;
    htmlRules.append(rule);

}

void MarkDownToHtml::createLabel()
{
    for(int i=1;i<=6;i++)
        labelHash[tr("<h%1>").arg(i)]=tr("</h%1>").arg(i);
    labelHash["<br>"]="";
    labelHash["<code>"]="</code>";
    labelHash["<hr"]="";
    labelHash["<strong>"]="</strong>";
    labelHash["<ol>"]="</ol>";
    labelHash["<li>"]="</li>";
    labelHash["<ul>"]="</ul>";


    nornalLabelList<<"<h1>"<<"<h2>"<<"<h3>"<<"<h4>"<<"<h5>"<<"<h6>"
                  <<"<strong>"<<"<hr>"<<"<br>"<<"<li>";


}
