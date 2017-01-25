#ifndef EDITACTION_H
#define EDITACTION_H

#include <QObject>

#include <pane/image/domain/image.h>


typedef QList<Image *> Images;
class EditAction:public QObject
{
    Q_OBJECT
public:
    EditAction();

public slots:
    void previewImages(Images images);
};

#endif // EDITACTION_H
