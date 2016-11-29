#include "imagepart.h"
#include "ui_imagepart.h"

ImagePart::ImagePart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagePart)
{
    ui->setupUi(this);
}

ImagePart::~ImagePart()
{
    delete ui;
}
