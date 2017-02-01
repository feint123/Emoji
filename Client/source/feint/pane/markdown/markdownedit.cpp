#include "highligherstyle.h"
#include "markdownedit.h"
#include "markdownparahighlighter.h"
#include  <QDebug>
#include <QDialog>
#include <QTextTable>
#include <pane/markdown/dialog/markdownimagedialog.h>
#include <QScrollBar>
#include <QMimeData>
#include <widget/button/markdownimagebutton.h>
#include <QFileSystemWatcher>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextDocumentFragment>
#include <widget/frame/imagepreview.h>
#include <util/dialogshowutil.h>
#include <util/documentutil.h>
#include <pane/markdown/domain/markimagesimple.h>
#include <util/json/jsondata.h>
#include <util/json/objecttojson.h>
#include <pane/menu/basemenu.h>
#include <util/graphic/animationutil.h>

MarkDownEdit::MarkDownEdit(QWidget *parent):
    QTextEdit(parent)
{


    fileUtil=new FileUtil();
    lighter=new MarkDownHighlighter(this->document());

    connect(this,SIGNAL(textChanged()),this,SLOT(updateImgBtnLine()));
}

void MarkDownEdit::setTheme()
{
    this->setObjectName("mark");


    this->setStyleSheet(tr("#mark{background:%1;border:none;color:%2}"


                                                   "QScrollBar::handle{border-radius:4px;background:%3;}"

                                                   "QScrollBar::add-line{height:1px;width:0px;}"

                                                   "QScrollBar::sub-line{height:0px;}"
                                                   "QScrollBar:vertical{width:8px;}").arg(background()).arg(color())
                        .arg(scrollHandle()));

    this->verticalScrollBar()->setStyleSheet(tr("QScrollBar:vertical::add-page,QScrollBar:vertical::add-page"
                                                "{background:%1;border-radius:4px;}").arg(scrollPage()));

    (*high)(this->lighter);
}


void MarkDownEdit::setQuickMenu(QMenu *value)
{
    quickMenu = value;
}

QMenu *MarkDownEdit::getQuickMenu() const
{
    return quickMenu;
}




/**
 * @brief MarkDownEdit::updateImgBtnLine
 * 更新图片按钮的位置。
 */
void MarkDownEdit::updateImgBtnLine()
{
    int cursorPos=this->textCursor().position();
    int scroll=this->verticalScrollBar()->value();
    if(!textChangedLock){
        clearImageBtns();
        QRegExp reg("\\!\\[[0-9]+\\]");
        QTextCursor textCursor=this->document()->find(reg);

        while(textCursor.anchor()>=0)
        {
            this->setTextCursor(textCursor);
            QString img=textCursor.block().text().trimmed();

            int id=(img.mid(2,img.length()-3)).toInt();

            createImageBtn(id,this->cursorRect().x(),cursorRect().y());


            textCursor=this->document()->find(reg,textCursor.anchor()+
                                              textCursor.block().length());
        }

    }
    QTextCursor textCursor=this->textCursor();
    textCursor.setPosition(cursorPos);
    this->setTextCursor(textCursor);
    this->verticalScrollBar()->setValue(scroll);
}

void MarkDownEdit::setNoteFile(QString noteFile)
{
    m_noteFile = noteFile;

    QFileSystemWatcher *watcher=new QFileSystemWatcher(this);
    watcher->addPath(defaultPath+"/"+noteFile+"_img.json");
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(updateImgBtnLine()));

}

void MarkDownEdit::setQuickString(const QString &value)
{
    quickString = value;
}

void MarkDownEdit::setHigh(const HighLighter &value)
{
    high = value;
}

MarkDownHighlighter *MarkDownEdit::getLighter() const
{
    return lighter;
}

QList<Image *> MarkDownEdit::getImageList()
{
    QList<Image *> imageList;
    for(MarkdownImageButton *btn:imageBtns)
        imageList.append(btn->getImage());
    return imageList;
}

QString MarkDownEdit::noteFile() const
{
    return m_noteFile;
}


void MarkDownEdit::insertImage(const QByteArray &url)
{
    createImageDialog();
    dialog->setImageUrl(url);
}

void MarkDownEdit::insertImage(const QImage &img)
{
    createImageDialog();
    dialog->setImage(img);
}

void MarkDownEdit::insertImage(bool drag)
{
    createImageDialog();
    dialog->setIsDrag(drag);
    dialog->setImageUrl("");
}

void MarkDownEdit::createImageDialog()
{

    dialog=MarkdownImageDialog::getInstance(this);
    dialog->setFlag(MarkdownImageDialog::NEW);
    dialog->setDefaultPath(this->defaultPath);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    DialogShowUtil::show(this,dialog);
    dialog->raise();
    disconnect(dialog,SIGNAL(insertImage(QString,QString,int,int)),
               this,SLOT(on_create_image(QString,QString,int,int)));

    connect(dialog,SIGNAL(insertImage(QString,QString,int,int)),
                this,SLOT(on_create_image(QString,QString,int,int)));

    hidePreview();

}




void MarkDownEdit::keyPressEvent(QKeyEvent *event)
{

     QTextEdit::keyPressEvent(event);

}


void MarkDownEdit::setDefaultPath(const QString &value)
{
    defaultPath = value;
    QStringList pathes(value);
    fileUtil->setLocalPathList(pathes);
}


/**
 * @brief MarkDownEdit::clearContent
 * 清除编辑器中的内容。文字和其他的一些附件。
 */
void MarkDownEdit::clearContent()
{
    this->clear();
    for(MarkdownImageButton *btn:this->imageBtns)
    {
        btn->deleteLater();
    }
    imageBtns.clear();
    update();
}

QList<MarkdownImageButton *> MarkDownEdit::getImageBtns() const
{
    return imageBtns;
}
//可以获取拖入文件的绝对路径
/**
 * @brief MarkDownEdit::dragEnterEvent
 * @param event
 * 使用拖拽方式插入图片
 */
void MarkDownEdit::dragEnterEvent(QDragEnterEvent *event)
{

    if(event->mimeData()->hasImage())
    {
        QImage image=qvariant_cast<QImage>(event->mimeData()->imageData());
        insertImage(image);
    }
    if(event->mimeData()->hasUrls())
        insertImage(event->mimeData()->urls().at(0).path().toUtf8());
}

void MarkDownEdit::wheelEvent(QWheelEvent *event)
{
    QTextEdit::wheelEvent(event);

    pixDelta=event->pixelDelta();
}

/**
 * @brief MarkDownEdit::dropEvent
 * @param event
 *
 */
void MarkDownEdit::dropEvent(QDropEvent *event)
{
    qDebug()<<"MarkdownEdit[dropEvent]";
}

void MarkDownEdit::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu=new QMenu();

    QAction *quick=new QAction(quickString,this);
    quick->setMenu(quickMenu);
    menu->addAction(quick);

    menu->addActions(getActionList());
    menu->exec(QCursor::pos());

    event->accept();
}



MarkDownToHtml *MarkDownEdit::getToHtml() const
{
    return toHtml;
}


/**
 * @brief MarkDownEdit::refreshFormat
 * 更新编辑器中文本的格式
 */
void MarkDownEdit::refreshFormat()
{
    this->selectAll();
    QTextCursor cursor=this->textCursor();
    this->setTabStopWidth(QFontMetrics(this->font()).maxWidth()*3);
    QTextBlockFormat format=cursor.blockFormat();
    format.setLineHeight(150,QTextBlockFormat::ProportionalHeight);
    cursor.setBlockFormat(format);
    cursor.clearSelection();
    this->setTextCursor(cursor);
}

void MarkDownEdit::on_insert_image()
{
    insertImage(false);
}

void MarkDownEdit::on_insert_url()
{

}
/**
 * @brief MarkDownEdit::createImageBtn
 * @param alt
 * @param path
 * @param w
 * @param h
 * @param pX
 * @param pY
 * @return
 * 构建图片按钮
*/
MarkdownImageButton *MarkDownEdit::createImageBtn(Image *image, int pX, int pY)
{
     MarkdownImageButton *imgBtn=new MarkdownImageButton(this->childAt(0,0));


     image->setTempPath(FileUtil::imageTempPath(defaultPath,image->file()));

     JsonData *datas=new JsonData(tr("%1/%2").arg(defaultPath).arg("images.json").toUtf8(),"images");
     datas->addOnlyByColumn<Image>("file",QVariant::fromValue(image->file()),image);

     imgBtn->setMinimumWidth(80);
     imgBtn->setImage(image);
     imgBtn->createView();
     imgBtn->setDefaultPath(this->defaultPath);
     imgBtn->setNoteFile(this->noteFile());
     imgBtn->setGeometry(pX,pY,imgBtn->width(),imgBtn->height());
     connect(imgBtn,SIGNAL(previewImage(MarkdownImageButton*)),this,SLOT(showPreview(MarkdownImageButton*)));
     connect(imgBtn,SIGNAL(hideImage()),this,SLOT(hidePreview()));

     this->imageBtns.append(imgBtn);

     delete datas;
   //  image->deleteLater();
}

MarkdownImageButton *MarkDownEdit::createImageBtn(int id,int px,int py)
{
     JsonData *datas=new JsonData(tr("%1/%2_%3").arg(defaultPath).
                                  arg(noteFile()).arg("img.json").toUtf8(),"images");

     Image *img=datas->selectById<Image>(id);
     if(img!=NULL)
        createImageBtn(img,px,py);

     delete datas;
    // img->deleteLater();
}

void MarkDownEdit::clearImageBtns()
{
    for(MarkdownImageButton *btn:imageBtns)
    {
        btn->close();
    }
    imageBtns.clear();
}
/**
 * @brief MarkDownEdit::on_create_image
 * @param alt
 * @param url
 * @param w
 * @param h
 * 生成图片按钮，代替图片的显示。
 */

void MarkDownEdit::on_create_image(QString alt, QString url, int w, int h)
{

    Image *image=new Image;
    image->setAlt(alt);
    image->setFile(url);
    image->setTempPath(FileUtil::imageTempPath(defaultPath,url));
    image->setWidth(w);
    image->setHeight(h);
    
    JsonData *datas=new JsonData(tr("%1/%2_%3").arg(defaultPath).arg(noteFile()).arg("img.json").toUtf8(),"images");
    int id=datas->addData<Image>(image);

    QString mark=tr("![%1]").arg(id);
    
    this->textCursor().insertText(mark+tr("\n"));
    this->textCursor().movePosition(QTextCursor::NextRow);

    delete datas;
    image->deleteLater();
}


void MarkDownEdit::showPreview(MarkdownImageButton *btn)
{

    currentImage=ImagePreview::getInstance(this);
    currentImage->setSize(QSize(btn->getImage()->width(),btn->getImage()->height()));

    currentImage->fixSize(this->size());
    currentImage->fixPosition(btn->geometry());
    currentImage->setPath(btn->getImage()->tempPath());
    currentImage->show();

}

void MarkDownEdit::hidePreview()
{
    currentImage=ImagePreview::getInstance(this);
    currentImage->close();
}





