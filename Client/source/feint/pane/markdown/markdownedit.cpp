#include "highligherstyle.h"
#include "markdownedit.h"
#include  <QDebug>
#include <QDialog>
#include <QTextTable>
#include <pane/markdown/dialog/markdownimagedialog.h>
#include <QScrollBar>
#include <QMimeData>
#include <widget/button/markdownimagebutton.h>
#include <QTextDocumentFragment>
#include <widget/frame/imagepreview.h>
#include <util/documentutil.h>

MarkDownEdit::MarkDownEdit(QWidget *parent):
    QTextEdit(parent)
{

    lighter=new MarkDownHighlighter(this->document());
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->verticalScrollBar()->hide();
    connect(this,SIGNAL(textChanged()),this,SLOT(updateImgBtnLine()));
    createActions();

}

void MarkDownEdit::setTheme(MarkDownEdit::Theme theme)
{
    if(theme==Theme::DARK)
        initDarkTheme();
}


void MarkDownEdit::initDarkTheme()
{
    this->setStyleSheet("background:#1f212b;border:none;color:#e7e9e8;font-size:13pt;");
    HighligherStyle::dark(this->lighter);
}

void MarkDownEdit::createActions()
{
    insert_image=new QAction(this);
    insert_url=new QAction(this);
    insert_table=new QAction(this);

    translateLanguage();
    this->addAction(insert_image);
    this->addAction(insert_url);
    this->addAction(insert_table);

    connect(insert_image,SIGNAL(triggered(bool)),this,SLOT(on_insert_image()));
    connect(insert_url,SIGNAL(triggered(bool)),this,SLOT(on_insert_url()));
    connect(insert_table,SIGNAL(triggered(bool)),this,SLOT(on_insert_table()));

}
/**
 * @brief MarkDownEdit::updateImgBtnLine
 * 更新图片按钮的位置。
 */
void MarkDownEdit::updateImgBtnLine()
{
    if(!textChangedLock){
    QRegExp reg("\\[img:id=[0-9]+\\]\\s*");
    QTextCursor textCursor=this->document()->find(reg);
    QList<MarkdownImageButton *> tempList;

    while(textCursor.anchor()>=0)
    {
        textCursor.movePosition(QTextCursor::StartOfBlock);

        for(MarkdownImageButton *btn:imageBtns)
        {
            if(btn->posMark()==textCursor.block().text().trimmed()){
                btn->updatePosition(this->cursorRect(textCursor));
                btn->setAnchor(textCursor.block().position());
                imageBtns.removeOne(btn);
                tempList.append(btn);
            }
        }
        textCursor=this->document()->find(reg,textCursor.anchor()+textCursor.block().length());
    }

    for(MarkdownImageButton *btn:imageBtns)
    {
        QTextCursor cursor=this->textCursor();
        cursor.setPosition(btn->anchor());
        cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
        this->setTextCursor(cursor);
        this->textCursor().removeSelectedText();
        btn->close();
    }
    imageBtns=tempList;
    tempList.clear();
    }
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
    dialog=new MarkdownImageDialog(this);
    dialog->setDefaultPath(this->defaultPath);
    dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->setGeometry(0,this->height()-dialog->height(),
                        dialog->width(),dialog->height());

    connect(dialog,SIGNAL(insertImage(QString,QString,int,int)),
                this,SLOT(on_create_image(QString,QString,int,int)));
}



void MarkDownEdit::translateLanguage()
{
    insert_image->setText(tr("插入图片"));
    insert_url->setText(tr("插入链接"));
    insert_table->setText(tr("插入表格"));
}

void MarkDownEdit::keyPressEvent(QKeyEvent *event)
{

     QTextEdit::keyPressEvent(event);
     if(event->key()==Qt::Key_Backspace)
     {

         for(MarkdownImageButton *btn:this->imageBtns)
         {
             if(btn->anchor()==this->textCursor().block().position())
             {
                 textChangedLock=true;
                 DocumentUtil::remove(this,textCursor().block().position(),
                                      textCursor().position()-textCursor().block().position());
                 this->imageBtns.removeOne(btn);
                 btn->close();
             }
         }
         textChangedLock=false;
     }

}

void MarkDownEdit::mousePressEvent(QMouseEvent *event)
{
    QTextEdit::mousePressEvent(event);

}

void MarkDownEdit::setDefaultPath(const QString &value)
{
    defaultPath = value;
}

void MarkDownEdit::setImageBtns(const QList<MarkdownImageButton *> &value)
{
    imageBtns = value;
    for(MarkdownImageButton *btn:value)
    {
        btn->setParent(this->childAt(0,0));
        btn->createView();
        int markWidth=btn->posMark().length()*QFontMetrics(this->font()).maxWidth();
        if(btn->width()<markWidth)
            btn->resize(markWidth,btn->height());
        connect(btn,SIGNAL(previewImage(MarkdownImageButton*)),this,SLOT(showPreview(MarkdownImageButton*)));
        connect(btn,SIGNAL(hideImage()),this,SLOT(hidePreview()));
    }
    this->updateImgBtnLine();
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
 * @brief MarkDownEdit::on_create_image
 * @param alt
 * @param url
 * @param w
 * @param h
 * 生成图片按钮，代替图片的显示。
 */

void MarkDownEdit::on_create_image(QString alt, QString url, int w, int h)
{
    MarkdownImageButton *imgBtn=new MarkdownImageButton(this->childAt(0,0));
    imgBtn->setImageTip(alt);
    imgBtn->setImagePath(url);
    imgBtn->setImageWidth(w);
    imgBtn->setImageHeight(h);
    imgBtn->setPosMark(tr("[img:id=%1]").arg(imageBtns.count()));
    imgBtn->setAnchor(this->textCursor().anchor());
    imgBtn->createView();
    //调整图片按钮的宽度
    int markWidth=imgBtn->posMark().length()*QFontMetrics(this->font()).maxWidth();
    if(imgBtn->width()<markWidth)
        imgBtn->resize(markWidth,imgBtn->height());
    imgBtn->setGeometry(this->cursorRect().x(),this->cursorRect().y()+
                        (this->cursorRect().height()-imgBtn->height())/2,
                        imgBtn->width(),imgBtn->height());
    connect(imgBtn,SIGNAL(previewImage(MarkdownImageButton*)),this,SLOT(showPreview(MarkdownImageButton*)));
    connect(imgBtn,SIGNAL(hideImage()),this,SLOT(hidePreview()));
    QString mark=tr("[img:id=%1]").arg(imageBtns.count());
    while(QFontMetrics(this->font()).width(mark)<imgBtn->width())
        mark+=" ";
    this->imageBtns.append(imgBtn);
    this->textCursor().insertText(mark+tr("\n"));
    this->textCursor().movePosition(QTextCursor::NextRow);
}


void MarkDownEdit::on_insert_table()
{
    QTextCursor cursor=this->textCursor();
    cursor.insertTable(5,5);
}

void MarkDownEdit::showPreview(MarkdownImageButton *btn)
{
    for(ImagePreview *p:previews)
        p->close();

    currentImage=new ImagePreview(this,QSize(btn->imageWidth(),btn->imageHeight()));
    currentImage->fixSize(this->size());
    currentImage->fixPosition(btn->geometry());
    currentImage->setPath(btn->imagePath());
    previews.append(currentImage);
    currentImage->show();

}

void MarkDownEdit::hidePreview()
{
    for(ImagePreview *p:previews)
        p->close();
}





