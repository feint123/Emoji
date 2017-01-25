#include "notebookdialog.h"
#include "ui_notebookdialog.h"

#include <domain/notebook.h>

#include <util/json/jsondata.h>

#include <util/fileutil.h>
#include <util/settinghelper.h>

#include <util/graphic/effectutil.h>

#include <QPainter>

#include <controller/notecontroller.h>

NotebookDialog::NotebookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotebookDialog)
{
    ui->setupUi(this); 
    EffectUtil::addDropShadow(25,this);
}

NotebookDialog::~NotebookDialog()
{
    delete ui;
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

void NotebookDialog::on_okBtn_clicked()
{
    NoteBook *noteBook=new NoteBook;
    noteBook->setFileName(tr("%1.json").arg(FileUtil::onlyName("notebook")));
    noteBook->setName(ui->lineEdit->text());
    noteBook->setCreateDate(QDateTime::currentDateTime());
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    data->addData<NoteBook>(noteBook);
    NoteController *controller=new NoteController();
    Setting *setting=SettingHelper::setting();
    setting->setCurrentNote(noteBook->fileName());
    setting->setCurrentBookName(noteBook->name());
    SettingHelper::saveSetting(setting);
    //向新建笔记本中添加默认笔记
    controller->addNote();
    this->close();
}

void NotebookDialog::on_cancelBtn_clicked()
{
    this->close();
}
