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

QString MarkdownManager::save(QString filePath, QList<MarkdownImageButton *> btnList, QString text)
{
    if(filePath.length()==0)
        filePath=QFileDialog::getSaveFileName(0,tr("储存文件"),QDir::currentPath(),tr("feint文件类型(*.fei)"));
    if(filePath.length()>0)
    {
        MarkContent *content=turnContent(text,filePath);
        QString contentText=tr(ObjectToJson::create(content).toJson());
        JsonData *json=new JsonData("","imgs");
        QString imgText=tr(json->createDoc<MarkImage>(turnToImage(btnList)).toJson());
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QString all=contentText+"&-_-&"+imgText;
            file.write(all.toUtf8());
            file.flush();
            file.close();
        }
    }
    return filePath;
}



void MarkdownManager::load(QString filePath)
{
    QList<MarkdownImageButton *> btnList;
    MarkContent *content;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QStringList datas=tr(file.readAll()).split("&-_-&");
        content=feint::JsonToObject::createObject<MarkContent>(QJsonDocument::fromJson(datas.at(0).toUtf8()).object());
        QJsonArray array=QJsonDocument::fromJson(datas.at(1).toUtf8()).object()["imgs"].toArray();
        for(int i=0;i<array.count();i++)
        {
            btnList.append(turnToMarkBtn(
                           feint::JsonToObject::createObject<MarkImage>(array.at(i).toObject())
                            ));
        }
    }
    this->btnList=btnList;
    this->content=content;
}

QList<MarkdownImageButton *> MarkdownManager::loadBtnList()
{
    return this->btnList;
}

MarkContent *MarkdownManager::loadContent()
{
    return this->content;
}
/**
 * @brief MarkdownManager::turnToImage
 * @param btnList
 * @return
 *
 * 将图像按钮列表转换成用来存储数据的MarkImage列表
 */
QList<MarkImage *> MarkdownManager::turnToImage(QList<MarkdownImageButton *> btnList)
{
    QList<MarkImage *> imgList;
    for(MarkdownImageButton *btn:btnList)
    {
        MarkImage *img=new MarkImage;
        img->setTip(btn->imageTip());
        img->setHeight(btn->imageHeight());
        img->setWidth(btn->imageWidth());
        img->setPosX(btn->x());
        img->setPosY(btn->y());
        img->setPath(btn->imagePath());
        img->setAnchor(btn->anchor());
        img->setMark(btn->posMark());
        imgList.append(img);
    }

    return imgList;
}

MarkContent *MarkdownManager::turnContent(QString text, QString title)
{
    MarkContent *content=new MarkContent;
    content->setContent(text);
    content->setDate(QDateTime::currentDateTime());
    content->setTitle(title);
    return content;
}

MarkdownImageButton *MarkdownManager::turnToMarkBtn(MarkImage *img)
{
    MarkdownImageButton *btn=new MarkdownImageButton;
    btn->setImageHeight(img->height());
    btn->setImageWidth(img->width());
    btn->setImagePath(img->path());
    btn->setImageTip(img->tip());
    btn->setAnchor(img->anchor());
    btn->setPosMark(img->mark());
    btn->move(img->posX(),img->posY());
    return btn;
}



