#ifndef IMAGEPART_H
#define IMAGEPART_H

#include "toolpart.h"

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QScrollArea>

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

public slots:
    void changeTextSize(int size);
    void changeTextFont(const QFont &font);
    void zoomIn();
    void zoomOut();
    void changeColor(int colorPart,ToolPart::ColorPart part);
private:
    void mousePressEvent(QMouseEvent *event);
    bool havePressHisText(QMouseEvent *event);
    void focusText(EmojiText *text);
    void createText();
    Ui::ImagePart *ui;
    QLabel *label;
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
