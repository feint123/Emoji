#ifndef MARKDOWNMANAGER_H
#define MARKDOWNMANAGER_H

#include <widget/button/markdownimagebutton.h>

#include <pane/markdown/domain/markcontent.h>
#include <pane/markdown/domain/markimage.h>

#include <util/fileutil.h>



class MarkdownManager:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    MarkdownManager();
    QString save(QString filePath, QString text);

    void load(QString filePath);

    MarkContent* loadContent();

    QString title() const;

public slots:
    void setTitle(QString title);

private:
    MarkContent *turnContent(QString text,QString title);

    MarkContent *content;

    QString m_title;
};

#endif // MARKDOWNMANAGER_H
