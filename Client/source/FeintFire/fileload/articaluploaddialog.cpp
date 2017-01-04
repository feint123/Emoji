#include "articaluploaddialog.h"
#include "ui_articaluploaddialog.h"

#include <QFileDialog>
#include <QDebug>
#include <util/json/objecttojson.h>
#include <pane/markdown/html/normalmarkdowntohtml.h>
#include <net/networkhelper.h>
#include <QJsonObject>
#include <QPainter>
#include <domain/response/uploadartical.h>
#include <util/graphic/innerdialogrect.h>

ArticalUploadDialog::ArticalUploadDialog(QWidget *parent) :
    UploadDialog(parent),
    ui(new Ui::ArticalUploadDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
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

void ArticalUploadDialog::paintEvent(QPaintEvent *event)
{
    InnerDialogRect *inner=new InnerDialogRect(InnerDialogRect::DOWN);
    inner->setTri(12);
    inner->draw(this,this->getDelay());
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

/**
 * @brief ArticalUploadDialog::on_postBtn_clicked
 * 开始对文章进行上传
 */
void ArticalUploadDialog::on_postBtn_clicked()
{
    QFile file(this->filePath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        UploadArtical *upload=new UploadArtical;
        NormalMarkDownToHtml *normal=new NormalMarkDownToHtml(QString(file.readAll()));
        upload->setContent(normal->createHtml());
        upload->setLabel(ui->labelFrame->getLabelString());
        upload->setType(ui->typeCom->currentText());
        upload->setTip(ui->tipEdit->toPlainText());
        upload->setTitle(ui->titleLine->text());
        NetworkHelper *helper=new NetworkHelper();
        helper->getJsonData("http://localhost:8080/artical/publish/10001",
                            ObjectToJson::create(upload).toJson());
        connect(helper,SIGNAL(jsonOk(QJsonDocument)),this,
                SLOT(on_upload_succcess(QJsonDocument)));
    }
}
/**
 * @brief ArticalUploadDialog::on_fileBtn_clicked
 * 选取需要上传对文章
 */
void ArticalUploadDialog::on_fileBtn_clicked()
{
    QString file=QFileDialog::getOpenFileName(this,QDir::currentPath(),"选取文章",tr("markdown文件(*.md)"));
    if(file.length()>0)
        filePath=file;
    ui->lineEdit->setText(file);
}

void ArticalUploadDialog::on_upload_succcess(QJsonDocument doc)
{
    qDebug()<<"upload: "<<doc.object()["code"].toInt();
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

void ArticalUploadDialog::onshared(bool shared, QString path)
{
    if(shared){
        this->show();
        ui->lineEdit->setText(path);
        this->filePath=path;
    }
}
