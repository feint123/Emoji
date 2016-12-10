#include "settingtextanalysis.h"

#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <domain/setting/textsetting.h>

SettingTextAnalysis::SettingTextAnalysis()
{

}

void *SettingTextAnalysis::analysis(QDomDocument *doc)
{
    QDomElement colors=doc->firstChildElement();
    QString style=colors.attribute("style");
    QDomNodeList colorList=colors.childNodes();

    TextSetting *textSetting=new TextSetting();
    for(int a=0;a<colorList.count();a++){
        if(colorList.at(a).toElement().attribute("name")==style)
        {
            QDomNodeList list=colorList.at(a).firstChild().childNodes();
            for(int i=0;i<list.count();i++)
            {
                qDebug()<<list.at(i).firstChild().nodeValue();
                textSetting->setColor(list.at(i).nodeName(),QColor(list.at(i).firstChild().nodeValue()));
            }
        }
    }
    return textSetting;
}


