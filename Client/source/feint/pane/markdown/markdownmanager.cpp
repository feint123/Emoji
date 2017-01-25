#include "markdownmanager.h"

#include <QFileDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <util/json/jsondata.h>
#include <util/json/jsontoobject.h>
#include <util/json/objecttojson.h>
#include <QDebug>
MarkdownManager::MarkdownManager()
{
}

QString MarkdownManager::save(QString filePath, QString text)
{
    if(filePath.length()==0)
        filePath=QFileDialog::getSaveFileName(0,tr("储存文件"),QDir::currentPath(),tr("feint文件类型(*.fei)"));
    if(filePath.length()>0)
    {
        MarkContent *content;
        content=turnContent(text,filePath);
        QString contentText=tr(ObjectToJson::create(content).toJson());

        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            file.write(contentText.toUtf8());
            file.flush();
            file.close();
        }
    }
    return filePath;
}



void MarkdownManager::load(QString filePath)
{
    MarkContent *content;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        content=feint::JsonToObject::createObject<MarkContent>(QJsonDocument::fromJson(file.readAll()).object());

    this->content=content;
}


MarkContent *MarkdownManager::loadContent()
{
    return this->content;
}

QString MarkdownManager::title() const
{
    return m_title;
}

void MarkdownManager::setTitle(QString title)
{
    m_title = title;
}


MarkContent *MarkdownManager::turnContent(QString text, QString title)
{
    MarkContent *content=new MarkContent;
    content->setContent(text);
    content->setDate(QDateTime::currentDateTime());
    if(this->title().length()==0)
        content->setTitle(title);
    else
        content->setTitle(this->title());
    return content;
}





