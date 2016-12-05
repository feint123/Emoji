#include "imagepart.h"
#include "ui_imagepart.h"

#include <QImageReader>
#include <QTextFormat>
#include <QDebug>
#include <QPainter>
#include <QTimer>

#include <graphic/imagebasicdeal.h>

ImagePart::ImagePart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagePart)
{
    ui->setupUi(this);
    this->label=new EmojiLabel();
    this->scrollArea=new QScrollArea();
    label->setBackgroundRole(QPalette::Base);
    label->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    label->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(label);
    scrollArea->setVisible(false);
    scrollArea->setStyleSheet("border:none");
    ui->tipLabel->hide();

    ui->verticalLayout->addWidget(scrollArea);
    connect(label,SIGNAL(editEmoji()),this,SLOT(showTip()));
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

void ImagePart::showTip()
{
    ui->tipLabel->show();
    QTimer *timer=new QTimer();
    timer->start(3000);
    connect(timer,SIGNAL(timeout()),ui->tipLabel,SLOT(hide()));
}


void ImagePart::setImage(const QImage &newImage)
{
    image=newImage;
    qDebug()<<"set pixmap start";
    label->setPixmap(QPixmap::fromImage(image));
    qDebug()<<"set pixmap end";
    scrollArea->setVisible(true);
    label->adjustSize();
    label->setPaintState(EmojiLabel::PaintState::LOADIMAGE);
}

QString ImagePart::getImagePath() const
{
    return imagePath;
}

void ImagePart::setImagePath(const QString &value)
{
    imagePath = value;
}

EmojiLabel *ImagePart::getEmojiLabel()
{
    return this->label;
}


