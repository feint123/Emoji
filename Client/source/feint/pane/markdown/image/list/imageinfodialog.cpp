#include "imageinfodialog.h"
#include "ui_imageinfodialog.h"
#include <QDateTime>
ImageInfoDialog::ImageInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageInfoDialog)
{
    ui->setupUi(this);
    setStyleSheet("background:white;color:#666;");
}

ImageInfoDialog::~ImageInfoDialog()
{
    delete ui;
}

void ImageInfoDialog::setImage(Image *image)
{
    ui->nameLab->setText(image->alt());
    ui->widthLab->setText(tr("%1").arg(image->width()));
    ui->heightLab->setText(tr("%1").arg(image->height()));
    ui->pathLab->setText(dealPath(image->tempPath()));
    ui->dateLab->setText(image->insertDate().toString("yyyy--MM--dd HH:mm::ss"));
}

QString ImageInfoDialog::dealPath(QString path)
{
    if(path.length()>33);
    path=path.mid(0,15)+"..."+path.mid(path.length()-15,path.length());
    return path;
}
