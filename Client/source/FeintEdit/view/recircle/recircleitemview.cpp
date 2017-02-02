#include "recircleitemview.h"

#include <QPainter>

#include <util/appcolorhelper.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/stringutil.h>

#include <QDebug>

#include <util/json/jsondata.h>

#include <domain/notebook.h>
#include <domain/notetip.h>
#include <domain/wordstatic.h>

#include <pane/markdown/markdownmanager.h>

#include <action/noteaction.h>

#include <widget/frame/shorttip.h>

#include <plug/appstatic.h>

RecircleItemView::RecircleItemView(QWidget *parent):
    QFrame(parent)
{
    lab=new QLabel(this);
    restore=createBtn(WordStatic::restore);
    del=createBtn(WordStatic::del);
    preview=createBtn(WordStatic::preview);

}

void RecircleItemView::setPage(RecirclePage *page)
{
    title=page->name();
    file=page->fileName();
    type=page->type();
    bookfile=page->bookFile();
    if(page->type()==RecirclePage::BOOK)
        img.load(":/image/rbook.svg");
    if(page->type()==RecirclePage::NOTE)
        img.load(":/image/rnote.svg");
    lab->setText(StringUtil::fitToLength(title,AppStatic::maxTitleLength));
    lab->setToolTip(title);
    lab->setStyleSheet(tr("color:%1;font-size:%2pt")
                       .arg(AppColorHelper::colorBot())
                       .arg(ScreenFit::fitToScreen(16)));

    lab->setAlignment(Qt::AlignCenter);


}

void RecircleItemView::restorePage()
{
    if(type==RecirclePage::NOTE)
        restoreNote();
    else if(type==RecirclePage::BOOK)
        restoreBook();


}

void RecircleItemView::deletePage()
{
    if(type==RecirclePage::NOTE)
        deleteNote(file,".fei");
    if(type==RecirclePage::BOOK)
        deleteBook();
}

QPushButton *RecircleItemView::createBtn(QString text)
{
    QPushButton *btn=new QPushButton(this);
    AppColor *color=AppColorHelper::loadColor();
    btn->setStyleSheet(tr("QPushButton{color:%1;background:%2;border:none}"
                          "QPushButton:pressed{background:%3}")
                       .arg(color->noteList()).arg(color->noteListShadow()).arg(color->menuCheck()));

    btn->setText(text);

    btn->hide();
    ScreenFit::fitFont(btn);
    return btn;
}

void RecircleItemView::restoreNote()
{
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");


    if(data->selectByColumn<NoteBook>("fileName",bookfile)==NULL)
    {
        //"笔记所在的笔记本不存在，请选择删除笔记。"
        wrongTip(WordStatic::tip_7);
        return;
    }
    delete data;
    data=new JsonData(SettingHelper::workPath(bookfile).toUtf8(),"notes");
    NoteTip *tip=new NoteTip;
    tip->setFileName(file);
    tip->setTitle(title);
    tip->setNotebook(bookfile);
    tip->setUpdateDate(QDateTime::currentDateTime());
    MarkdownManager *manager=new MarkdownManager;
    manager->load(SettingHelper::workPath(this->file+".fei"));
    tip->setTip(manager->loadContent()->content());
    data->addOnlyByColumn<NoteTip>("fileName",tip->fileName(),tip);
    delete data;
    tip->deleteLater();

    deleteFrameRecircle(this->file);
}

void RecircleItemView::restoreBook()
{
    JsonData *data=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    NoteBook *book=new NoteBook;
    book->setFileName(this->file);
    book->setCreateDate(QDateTime::currentDateTime());
    book->setName(this->title);
    data->addOnlyByColumn<NoteBook>("fileName",bookfile,book);
    delete data;
    book->deleteLater();

    deleteFrameRecircle(this->file);
}

void RecircleItemView::deleteNote(QString filename,QString after)
{
    QFile file(SettingHelper::workPath(filename+after));
    file.remove();

    deleteFrameRecircle(filename);
}

void RecircleItemView::deleteBook()
{
    JsonData *data=new JsonData(SettingHelper::workPath("recircles.json").toUtf8(),"recircles");
    for(RecirclePage *page:data->selectAll<RecirclePage>())
    {
        if(page->bookFile()==this->file&&page->type()==RecirclePage::NOTE)
        deleteNote(page->fileName(),".fei");
        page->deleteLater();
    }
    deleteNote(this->file,"");
    delete data;
}

void RecircleItemView::deleteFrameRecircle(QString filename)
{
    JsonData *data=new JsonData(SettingHelper::workPath("recircles.json").toUtf8(),"recircles");

    RecirclePage *page=data->selectByColumn<RecirclePage>("fileName",filename);
    if(page!=NULL)
        data->deleteData(page->id());
    delete data;
}

void RecircleItemView::wrongTip(QString tips)
{
    QWidget *parent=(QWidget *)this->parent();
    ShortTip *tip=ShortTip::getInstance(parent);
    tip->setTipStr(tips);

    tip->showTip(1500);

    tip->setGeometry((parent->width()-tip->width())/2,
                     (parent->height()-tip->height())/2,
                     tip->width(),tip->height());


}

void RecircleItemView::paintEvent(QPaintEvent *event)
{
    QImage img;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QMatrix matrix;
    float scale=(this->width()*0.8)/(float)this->img.width();
    matrix.scale(scale,this->height()/(float)this->img.height());
    img=this->img.transformed(matrix);
    painter.drawImage(this->width()/2-img.width()/2,
                      this->height()/2-img.height()/2,img);
}

void RecircleItemView::resizeEvent(QResizeEvent *event)
{
    lab->resize(this->width(),lab->height());
    lab->setGeometry((this->width()-lab->width())/2,(this->height()-lab->height())/2,
                     lab->width(),lab->height());


    del->resize(this->height(),this->height());
    restore->resize(this->height(),this->height());
    preview->resize(this->height(),this->height());
    preview->setGeometry(this->width()/2-preview->width()*1.5,0,preview->width(),preview->height());
    del->setGeometry(preview->x()+del->width(),0,preview->width(),preview->height());
    restore->setGeometry(preview->x()+2*preview->width(),
                         0,preview->width(),preview->height());
}

void RecircleItemView::enterEvent(QEvent *event)
{
    connect(restore,SIGNAL(clicked(bool)),this,SLOT(restorePage()));
    connect(del,SIGNAL(clicked(bool)),this,SLOT(deletePage()));
    restore->show();
    del->show();
    preview->show();
}

void RecircleItemView::leaveEvent(QEvent *event)
{
    disconnect(restore,SIGNAL(clicked(bool)),this,SLOT(restorePage()));
    disconnect(del,SIGNAL(clicked(bool)),this,SLOT(deletePage()));
    restore->hide();
    del->hide();

    preview->hide();
}


