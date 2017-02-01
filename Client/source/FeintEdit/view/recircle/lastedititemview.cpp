#include "lastedititemview.h"

#include <qpainter.h>
#include <QDebug>
#include <qboxlayout.h>
#include <QScrollBar>
#include <util/appcolorhelper.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <graphic/screenhelper.h>
#include <plug/appstatic.h>
#include <util/json/jsondata.h>
#include <domain/appmessage.h>
#include <domain/notetip.h>
#include <domain/wordstatic.h>
#include <view/menuline.h>
LastEditItemView::LastEditItemView(QWidget *parent):
    QFrame(parent)
{
    createView();
    setWindowFlags(Qt::FramelessWindowHint);
}

void LastEditItemView::setLastEdit(LastEdit *edit)
{
    id=edit->id();
    file=edit->file();
    bookFile=edit->bookFile();
    title->setText(edit->title());
    content->setText(edit->tip());
    QString format="yyyy年MM月dd日 HH:mm:ss";
    data->setText(edit->updateDate().toString(format));
    hasNote=checkhasNote(file,bookFile);
}

void LastEditItemView::removeLastEdit()
{
    JsonData *data=new JsonData(SettingHelper::workPath(AppMessage::getFileName(AppMessage::LASTEDIT)+".json").toUtf8(),
                                AppMessage::getFileName(AppMessage::LASTEDIT));

    data->deleteData(id);

    delete data;
}

void LastEditItemView::openNote()
{
    AppStatic::currentNote=file;
    AppStatic::currentBook=bookFile;
    MenuLine::getInstance()->setClickItem(0);
}

void LastEditItemView::createView()
{
    setObjectName("last");

    title=createLabel();

    content=new QTextEdit(this);
    content->setEnabled(false);
    content->verticalScrollBar()->setVisible(false);
    content->setStyleSheet("QTextEdit{background:transparent;color:#eee;border:none;}");
    ScreenFit::fitFont(content);
    data=createLabel();
    QVBoxLayout *vb=new QVBoxLayout(this);
    vb->addWidget(title);
    vb->addWidget(content);
    vb->addWidget(data);
    vb->setSpacing(4);
    this->setLayout(vb);
    img.load(":/image/line_1.png");
    deleteImage.load(":/image/delete_mark.png");
    remove=createBtn(WordStatic::remove);
    open=createBtn(WordStatic::open);
    remove->hide();
    open->hide();

}

bool LastEditItemView::checkhasNote(QString file, QString bookFile)
{

    JsonData *data=new JsonData(SettingHelper::workPath(bookFile).toUtf8(),"notes");
    if(data->selectByColumn<NoteTip>("fileName",file)==NULL){
        delete data;
        return false;
    }
    else{
        delete data;
        return true;
    }
}

QPushButton *LastEditItemView::createBtn(QString text)
{
    QPushButton *btn=new QPushButton(this);
    btn->setText(text);
    ScreenFit::fitFont(btn);
    btn->resize(60,21);
    ScreenFit::fit(btn);
    btn->setStyleSheet("QPushButton{border:none;color:#f9f9f9;background:transparent;"
                       "border-radius:5px;}"
                       "QPushButton:pressed{border:1px solid #eee;}");
    return btn;
}

QLabel *LastEditItemView::createLabel(QString text)
{
    QLabel *lab=new QLabel(this);
    ScreenFit::fitFont(lab);
    lab->setText(text);
    lab->setStyleSheet(tr("QLabel{color:#f9f9f9};"));
    return lab;
}


void LastEditItemView::resizeEvent(QResizeEvent *event)
{

    int padding=12;

    padding=ScreenFit::fitToScreen(padding);

    open->setGeometry(this->width()-open->width()-padding,this->height()-padding-open->height(),
            open->width(),open->height());
    remove->setGeometry(open->x()-padding/2-remove->width(),open->y(),
                        remove->width(),remove->height());

}

void LastEditItemView::paintEvent(QPaintEvent *event)
{
    QImage img;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QMatrix matrix;
    float scale=this->width()/(float)this->img.width();
    matrix.scale(scale,1);
    img=this->img.transformed(matrix);
    painter.drawImage(0,0,img);

    painter.drawImage(0,this->height()-img.height(),img);

    if(!hasNote)
        painter.drawImage((this->width()-deleteImage.width())/2,
                          (this->height()-deleteImage.height())/2,deleteImage);

}

void LastEditItemView::enterEvent(QEvent *event)
{
    connect(remove,SIGNAL(clicked(bool)),this,SLOT(removeLastEdit()));
    connect(open,SIGNAL(clicked(bool)),this,SLOT(openNote()));
    remove->show();
    if(hasNote)
        open->show();
}

void LastEditItemView::leaveEvent(QEvent *event)
{
    remove->hide();
    open->hide();
    disconnect(open,SIGNAL(clicked(bool)),this,SLOT(openNote()));
    disconnect(remove,SIGNAL(clicked(bool)),this,SLOT(removeLastEdit()));
}
