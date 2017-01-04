#ifndef MARKDOWNMANAGER_H
#define MARKDOWNMANAGER_H

#include <widget/button/markdownimagebutton.h>

#include <pane/markdown/domain/markcontent.h>
#include <pane/markdown/domain/markimage.h>



class MarkdownManager:public QObject
{
    Q_OBJECT
public:
    MarkdownManager();
    QString save(QString filePath,QList<MarkdownImageButton *> btnList,QString text);

    void load(QString filePath);

    QList<MarkdownImageButton *> loadBtnList();
    MarkContent* loadContent();

private:
    QList<MarkImage *> turnToImage(QList<MarkdownImageButton *> btnList);
    MarkContent *turnContent(QString text,QString title);

    MarkdownImageButton *turnToMarkBtn(MarkImage *img);

    QList<MarkdownImageButton *> btnList;
    MarkContent *content;
};

#endif // MARKDOWNMANAGER_H
