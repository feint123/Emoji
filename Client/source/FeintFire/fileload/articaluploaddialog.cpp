#include "articaluploaddialog.h"
#include "ui_articaluploaddialog.h"

#include <QFileDialog>

ArticalUploadDialog::ArticalUploadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArticalUploadDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->raise();
}

ArticalUploadDialog::~ArticalUploadDialog()
{
    delete ui;
}
/**
 * @brief ArticalUploadDialog::changeEvent
 * @param e
 */
void ArticalUploadDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch(e->type()){
        case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString ArticalUploadDialog::getFilePath() const
{
    return filePath;
}

void ArticalUploadDialog::setFilePath(const QString &value)
{
    filePath = value;
}

void ArticalUploadDialog::on_quitBtn_clicked()
{
    this->close();
}

void ArticalUploadDialog::on_postBtn_clicked()
{

}

void ArticalUploadDialog::on_fileBtn_clicked()
{
    QString file=QFileDialog::getOpenFileName(this,QDir::currentPath(),"选取文章",tr("markdown文件(*.md)"));
    if(file.length()>0)
        filePath=file;
    ui->lineEdit->setText(file);
}

QStringList ArticalUploadDialog::getTypeList() const
{
    return typeList;
}

void ArticalUploadDialog::setTypeList(const QStringList &value)
{
    typeList = value;
    ui->typeCom->clear();
    ui->typeCom->addItems(value);
}
