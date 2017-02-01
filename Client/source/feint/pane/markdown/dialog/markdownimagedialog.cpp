#include "markdownimagedialog.h"
#include "ui_markdownimagedialog.h"

#include <QCryptographicHash>
#include <QFileDialog>
#include <QDebug>
#include <QStandardPaths>

#include <util/graphic/imageutil.h>
MarkdownImageDialog *MarkdownImageDialog::dialog=NULL;
MarkdownImageDialog::MarkdownImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarkdownImageDialog)
{
    ui->setupUi(this);
    ui->widthLine->setEnabled(false);
    ui->heightLine->setEnabled(false);
}

void MarkdownImageDialog::setImageUrl(const QByteArray &url)
{
    createDialog(tr(url));
}

void MarkdownImageDialog::setImage(const QImage &img)
{
    createDialog(img);
}

void MarkdownImageDialog::setIsDrag(bool drag)
{
    this->drag=drag;
}

MarkdownImageDialog::~MarkdownImageDialog()
{
    delete ui;
    dialog=NULL;
}

MarkdownImageDialog *MarkdownImageDialog::getInstance(QWidget *parent)
{
    if(dialog==NULL){
        dialog=new MarkdownImageDialog(parent);
        qDebug()<<"markdownimagedialog"<<"getInstance";
    }
    return dialog;
}

void MarkdownImageDialog::on_imageBtn_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"选择图片",
                                                  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0),
                                                  tr("压缩图片(*.jpg *.jpeg);;网络图片(*.png)"));
    if(filePath.length()>0)
    {
        createDialog(filePath);
    }
}

void MarkdownImageDialog::on_widthLine_textChanged(const QString &arg1)
{
    int currentWidth=arg1.toInt();
    ui->heightLine->setText(QString::number(imgHeight*(float)((float)currentWidth/(float)imgWidth)));
}

void MarkdownImageDialog::on_okBtn_clicked()
{
    if(ui->altLine->text().length()==0){

        ui->altLine->setFocus();
    }else{
        QString fileName="";

        QString path=tr("%1/%2.png").arg(this->defaultPath).arg("cache");
        QFile file(path);
        this->img.save(&file);
        file.close();
        file.open(QIODevice::ReadOnly);
        fileName=QCryptographicHash::hash(file.readAll(),QCryptographicHash::Md5).toHex().constData();
        file.close();

        saveImage(fileName);
        if(flag==NEW)
            emit insertImage(ui->altLine->text(),fileName,imgWidth,imgHeight);
        if(flag==UPDATE)
            emit updateImage(ui->altLine->text());
        this->close();
    }

}

void MarkdownImageDialog::createDialog(QString filePath)
{
    QImage img(filePath);
    createDialog(img);
    ui->imageLine->setText(filePath);
}

void MarkdownImageDialog::createDialog(const QImage &img)
{
    if(!img.isNull()||!drag)
    {
        this->img=img;
        imgWidth=img.width();
        imgHeight=img.height();
        ui->widthLine->setText(QString::number(imgWidth));
        ui->heightLine->setText(QString::number(imgHeight));
        ui->widthLine->setEnabled(true);
    }
}

void MarkdownImageDialog::setFlag(const FLAG &value)
{
    flag = value;
}

void MarkdownImageDialog::saveImage(QString imgName)
{
    ImageUtil::saveImage(defaultPath,imgName,this->img);
}

void MarkdownImageDialog::setDefaultPath(const QString &value)
{
    defaultPath = value;
}

void MarkdownImageDialog::on_pushButton_clicked()
{
    this->close();
}

void MarkdownImageDialog::setImgHeight(int value)
{
    imgHeight = value;
    ui->heightLine->setText(QString::number(imgHeight));
}

void MarkdownImageDialog::setImgTip(QString tip)
{
    ui->altLine->setText(tip);
}

void MarkdownImageDialog::setImgWidth(int value)
{
    imgWidth = value;
    ui->widthLine->setText(QString::number(imgWidth));
}
