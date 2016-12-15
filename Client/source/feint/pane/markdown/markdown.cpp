#include "markdown.h"
#include "ui_markdown.h"

#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

MarkDown::MarkDown(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::markdown)
{
    ui->setupUi(this);
    markdown=new MarkDownEdit();
    markdown->setTheme(MarkDownEdit::DARK);
    ui->verticalLayout->addWidget(markdown);
}

MarkDown::~MarkDown()
{
    delete ui;
}

void MarkDown::on_fileBtn_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,tr("笔记"),QDir::currentPath(),
                                                 tr("MarkDown(*.md)"));
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream *stream=new QTextStream(&file);
        this->markdown->setText(stream->readAll());
    }

}

void MarkDown::on_saveBtn_clicked()
{
    QString content=this->markdown->toPlainText();
    QString outPath=QFileDialog::getSaveFileName(this,tr("保存"),QDir::currentPath(),
                                                 tr("MarkDown(*.md)"));
    QFile file(outPath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        file.write(content.toUtf8());
        if(file.flush()){
             file.close();
             qDebug()<<"MarkDown[on_saveBtn_clicked]: "<<"Save success";
        }
    }

}
