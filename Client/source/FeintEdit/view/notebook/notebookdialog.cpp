#include "notebookdialog.h"
#include "ui_notebookdialog.h"

#include <domain/notebook.h>
#include <domain/wordstatic.h>

#include <util/json/jsondata.h>

#include <util/fileutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>

#include <util/graphic/effectutil.h>

#include <QPainter>

#include <controller/notecontroller.h>
NotebookDialog *NotebookDialog::dialog=NULL;
NotebookDialog::NotebookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotebookDialog)
{
    ui->setupUi(this); 
    setAttribute(Qt::WA_DeleteOnClose);
    EffectUtil::addDropShadow(25,this);
    ScreenFit::fitFont(ui->label);
    ScreenFit::fitWithFont(ui->cancelBtn);
    ScreenFit::fitWithFont(ui->okBtn);
    ScreenFit::fitWithFont(ui->lineEdit);
    ui->label->setText(WordStatic::new_+WordStatic::book);
    ui->okBtn->setText(WordStatic::ok);
    ui->cancelBtn->setText(WordStatic::cancel);
    ui->lineEdit->setPlaceholderText(WordStatic::tip_2);

}

NotebookDialog *NotebookDialog::getInstance(QWidget *parent)
{
    if(dialog==NULL){
        dialog=new NotebookDialog(parent);
        ScreenFit::fit(dialog);
    }
    else if(dialog->parent()!=parent&&parent!=0)
        dialog->setParent(parent);

    return dialog;
}

NotebookDialog::~NotebookDialog()
{
    dialog=NULL;
    delete ui;
}

void NotebookDialog::setTitle(QString title)
{
    ui->label->setText(title);
}

void NotebookDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
  //  painter.setRenderHint(QPainter::Antialiasing);
    QBrush brush;
    brush.setColor(QColor(255, 255, 255, 230));
    brush.setStyle(Qt::SolidPattern);
    QPen pen;
    pen.setColor(QColor(0,0,0,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0,0,this->width(),this->height());

}

void NotebookDialog::resizeEvent(QResizeEvent *event)
{
    ui->okBtn->setGeometry(ui->lineEdit->x()+ui->lineEdit->width()-ui->okBtn->width(),
                           ui->lineEdit->y()+ui->lineEdit->height()*2,
                           ui->okBtn->width(),ui->okBtn->height());
    ui->cancelBtn->setGeometry(ui->okBtn->x()-ui->okBtn->width()-ScreenFit::fitToScreen(8),
                               ui->okBtn->y(),
                               ui->cancelBtn->width(),ui->cancelBtn->height());
}

void NotebookDialog::on_okBtn_clicked()
{
    emit ready(ui->lineEdit->text());
    this->deleteLater();
}

void NotebookDialog::on_cancelBtn_clicked()
{
    this->close();
}
