#ifndef IMAGEPART_H
#define IMAGEPART_H

#include "emojilabel.h"


#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QScrollArea>
#include<pane/toolpart.h>
#include <graphic/emojitext.h>
#include <graphic/imagerender.h>

namespace Ui {
class ImagePart;
}

class ImagePart : public QDialog
{
    Q_OBJECT

public:
    explicit ImagePart(QWidget *parent = 0);
    ~ImagePart();
    bool loadFile();
    QString getImagePath() const;
    void setImagePath(const QString &value);
    EmojiLabel* getEmojiLabel();
public slots:
    void zoomIn();
    void zoomOut();
    void changeColor(int colorPart,ToolPart::ColorPart part);
private slots:
    void showTip();
private:
    Ui::ImagePart *ui;
    EmojiLabel *label;
    QString imagePath;
    QImage image;
    QScrollArea *scrollArea;
    void setImage(const QImage &image);
    ImageRender render;
    double scaleFactor;
    int r=50,g=50,b=50;

    QList<EmojiText *> textList;
};

#endif // IMAGEPART_H
