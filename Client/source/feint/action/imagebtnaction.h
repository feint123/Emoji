#ifndef IMAGEBTNACTION_H
#define IMAGEBTNACTION_H

#include <QObject>
#include <QTextDocument>

#include <pane/markdown/domain/markimagesimple.h>

#include <pane/image/domain/image.h>



class ImageBtnAction:public QObject
{
    Q_OBJECT
public:
    ImageBtnAction();

public slots:
    void updateImgInfo(QWidget *parent, Image *img, QString defaultPath);

private slots:
    void updateImgName(QString name);

private:
    int id;
    QString defaultPath;
};

#endif // ß
