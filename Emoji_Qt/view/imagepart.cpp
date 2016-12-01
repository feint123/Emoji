#include "imagepart.h"
#include "ui_imagepart.h"

#include <QImageReader>
#include <QTextFormat>
#include <QDebug>

#include <graphic/imagebasicdeal.h>

ImagePart::ImagePart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagePart)
{
    ui->setupUi(this);
    this->label=new QLabel();
    this->scrollArea=new QScrollArea();
    label->setBackgroundRole(QPalette::Base);
    label->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    label->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(label);
    scrollArea->setVisible(false);
    scrollArea->setStyleSheet("border:none");

    ui->horizontalLayout_2->addWidget(scrollArea);
}

ImagePart::~ImagePart()
{
    delete ui;
}

bool ImagePart::loadFile()
{
    QImageReader reader(this->imagePath);
    reader.setAutoTransform(true);
    QImage newImage=reader.read();
    if(newImage.isNull())
    {
        return false;
    }
    setImage(newImage);
    scrollArea->setAlignment(Qt::AlignCenter);

    scaleFactor=1.0;
    return true;
}

void ImagePart::changeTextSize(int size)
{
    QFont font=label->font();
    font.setPointSize(size);
    this->label->setFont(font);

}

void ImagePart::changeTextFont(const QFont &font)
{
    this->label->setFont(font);
}

void ImagePart::zoomIn()
{
    if (scaleFactor<8)
        ImageBasicDeal::scaleImage(label,2,&scaleFactor);
}

void ImagePart::zoomOut()
{

    if(scaleFactor>0.125)
        ImageBasicDeal::scaleImage(label,0.5,&scaleFactor);
}

void ImagePart::changeColor(int colorPart, ToolPart::ColorPart part)
{
    render.setImage(image);
    switch (part) {
    case ToolPart::ColorPart::RED:
        r=colorPart;
        break;
    case ToolPart::ColorPart::GREEN:
        g=colorPart;
        break;
    case ToolPart::ColorPart::BLUE:
        b=colorPart;
    default:
        break;
    }
    label->setPixmap(QPixmap::fromImage(render.changeRgb(r,g,b)));
}

void ImagePart::mousePressEvent(QMouseEvent *event)
{
    if(!havePressHisText(event))
    {
        createText();
    }
}

bool ImagePart::havePressHisText(QMouseEvent *event)
{
    bool isInHis=false;
    foreach(EmojiText* text,textList)
    {
        if(event->x>text->getX()&&event->x<(text->getX+text->getWidth())&&
                event->y>text->getY()&&event->y<(text->getY+text->getHeight()))
        {
            isInHis=true;
            focusText(text);
            break;
        }
    }
    return isInHis;
}

void ImagePart::focusText(EmojiText *text)
{

}

void ImagePart::setImage(const QImage &newImage)
{
    image=newImage;
    label->setPixmap(QPixmap::fromImage(image));
    scrollArea->setVisible(true);
    label->adjustSize();
}

QString ImagePart::getImagePath() const
{
    return imagePath;
}

void ImagePart::setImagePath(const QString &value)
{
    imagePath = value;
}


