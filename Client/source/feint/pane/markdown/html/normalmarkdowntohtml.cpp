#include "htmlbuilder.h"
#include "markdowntohtml.h"
#include "normalmarkdowntohtml.h"
#include <QTextDocument>
#include <QDebug>
NormalMarkDownToHtml::NormalMarkDownToHtml(QString markdown)
{
    this->markdown=markdown;

    html=new MarkDownToHtml();
    this->htmlRules.append(html->getHtmlRules());
    this->labelHash=html->getLabelHash();
    orderlistUnClose=0;
    unOrderListUnClose=0;
    isFirstUnOrder=true;
}

QStringList NormalMarkDownToHtml::splitMarkDown()
{
    return markdown.split("\n");
}

NormalMarkDownToHtml::LineHtml NormalMarkDownToHtml::paserLine(QString text)
{
    QString currentText=text;
    LineHtml line;
    line.type=1;
    foreach (const HtmlRule &rule, htmlRules) {

        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);

        while (index >= 0) {
            if(getLineType(rule.label)==2) line.type=2;

            int length = expression.matchedLength();

            int offset=0;

            if(rule.type==3)
                paserOrderList(&text,index,length,rule);
            else{
                QString end="";
                if(!orderListList.isEmpty()&&orderListList.last().text!=currentText)
                {
                    end=endOrderList(0);
                    orderListList.clear();
                }
                offset=end.length();
                text.replace(index,rule.markLength,end+rule.label);

                if(rule.endType!=0)
                    text.replace(offset+index+length+rule.label.length()-rule.markLength*2,
                                 rule.markLength,labelHash[rule.label]);
                else
                    text.insert(offset+index+length+rule.label.length()-rule.markLength
                            ,labelHash[rule.label]);
            }

            index = expression.indexIn(text, index + length);
        }

    }
    line.text=text;
    return line;
}

int NormalMarkDownToHtml::getLineType(QString label)
{
    if(html->getNornalLabelList().contains(label))
        return 1;
    else
        return 2;
}


void NormalMarkDownToHtml::paserOrderList(QString *text, int index, int length, HtmlRule rule)
{


    OrderList order;
    order.level=getTabNum(*text);
    order.orderType=rule.label;
    order.text=*text;
    text->trimmed();
    if(rule.label=="<ol>")
        rule.markLength=text->indexOf(".")+1;
    else
        rule.markLength=2;

    if(orderListList.isEmpty())
    {
        text->replace(index,rule.markLength,tr("%1<li>").arg(order.orderType));
        orderListList.append(order);
    }
    else if( orderListList.last().level<order.level)
    {
        QString start="";
        for(int i=0;i<order.level-orderListList.last().level;i++)
            start+=tr("%1<li>").arg(order.orderType);
        text->replace(index,rule.markLength,start);
        orderListList.append(order);
    }
    else if(orderListList.last().level>order.level)
    {
        QString end="";
        for(int i=0;i<orderListList.last().level-order.level;i++)
            end+=tr("</li>%1").arg(order.orderType);
        end+="</li><li>";
        text->replace(index,rule.markLength,end);
        orderListList.append(order);
    }
    else if(orderListList.last().level==order.level)
    {
         text->replace(index,rule.markLength,tr("</li><li>"));
         orderListList.append(order);
    }


}

QString NormalMarkDownToHtml::endOrderList(int endIndex)
{
    QString end="";
    if(!orderListList.isEmpty())
    {
        for(int j=orderListList.count()-1;j>=endIndex;j--){
            for(int i=0;i<orderListList.at(j).level;i++)
            {
                end+=tr("</li>%1").arg(labelHash[orderListList.at(j).orderType]);

            }
        }
    }
    return end;
}


int NormalMarkDownToHtml::getTabNum(QString str)
{
    QRegExp reg("^\\t*");
    if(reg.indexIn(str)>=0)
        return reg.matchedLength()+1;
    else return 1;
}



QString NormalMarkDownToHtml::createHtml()
{
    HtmlBuilder *builder=new HtmlBuilder();
    QString body;

    QStringList document=splitMarkDown();
    for(int i=0;i<document.count();i++)
    {

        LineHtml line=paserLine(document.at(i));
        if(line.type==1)
            body+="<pre>"+line.text+"</pre>";
        else
            body+=line.text;
    }
    builder->setBody(body);
    return builder->getHtml();
}

