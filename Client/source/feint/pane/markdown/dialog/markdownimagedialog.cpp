#include "markdownimagedialog.h"
#include "ui_markdownimagedialog.h"

#include <QFileDialog>

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
}

void MarkdownImageDialog::on_imageBtn_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"选择图片",QDir::currentPath(),
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
        this->setToolTip("图片替代名称不能为空");
        ui->altLine->setFocus();
    }else{
        QString path=tr("%1/%2.png").arg(this->defaultPath).arg(ui->altLine->text());
        this->img.save(path);
        emit insertImage(ui->altLine->text(),path,imgWidth,imgHeight);
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
        this->show();
    }
}

void MarkdownImageDialog::setDefaultPath(const QString &value)
{
    defaultPath = value;
}

void MarkdownImageDialog::on_pushButton_clicked()
{
    this->close();
}
