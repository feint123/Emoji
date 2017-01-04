#include "markdown.h"
#include "markdowncache.h"
#include "ui_markdown.h"

#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QScrollBar>
#include <pane/markdown/html/normalmarkdowntohtml.h>
#include <graphic/screenhelper.h>
#include <fbutton.h>
#include <util/json/jsondata.h>
#include <widget/frame/imagepreview.h>
/**
 *
 * 当文本内容发生改变之后，隔2s将编辑器中的内容存入缓存文件当中，若程序意外退出，再
 * 次回到编辑器中则显示最近一次的缓存内容。
 */
MarkDown::MarkDown(QWidget *parent, UploadDialog *uploadWidget, int miniWidth) :
    QWidget(parent),
    ui(new Ui::markdown)
{
    ui->setupUi(this);

    this->setMinimumWidth(miniWidth);

    this->uploadWidget=uploadWidget;
    this->uploadWidget->hide();
    this->uploadWidget->setParent(this);

    setTitle("Untitled");

    createActions();

    ui->fToogleButton->setChecked(true);

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(on_save_cache()));

    manager=new MarkdownManager;
}


MarkDown::~MarkDown()
{
    delete timer;
    delete ui;
}
/**
 * 打开文件
 * 应该根据不同的文件类型选择不同的加载方式
 * @brief MarkDown::on_fileBtn_clicked
 */
void MarkDown::on_fileBtn_clicked()
{
    markdown->clearContent();
    QString filePath=QFileDialog::getOpenFileName(this,tr("笔记"),QDir::currentPath(),
                                                 tr("MarkDown(*.md);;feint文件类型(*.fei)"));
    if(filePath.length()>0)
    {
        manager->load(filePath);
        this->markdown->setText(manager->loadContent()->content());
        markdown->refreshFormat();
        markdown->setImageBtns(manager->loadBtnList());
    }
}

void MarkDown::on_saveBtn_clicked()
{
    saveFile();
}

/**
 * @brief MarkDown::on_shareBtn_clicked
 * 对文章进行分享。
 */
void MarkDown::on_shareBtn_clicked()
{
    QString filePath=saveFile();
    if(filePath.length()>0){
        emit startSharing(true,filePath);
    }else
        emit startSharing(false,tr(""));
}
/**
 * @brief MarkDown::on_text_changed
 * 当编辑器中的内容发生变化时，给文章的标题加上*号
 */
void MarkDown::on_text_changed()
{
    if(!this->title.contains("*"))
        this->setTitle(this->title+"*");

    if(!timer->isActive())
    {
        timer->setInterval(15000);
        timer->start();
    }
}
/**
 * @brief MarkDown::on_save_cache
 * 将文本内容保存到缓存文件当中。
 */
void MarkDown::on_save_cache()
{
    JsonData *data=new JsonData(this->cachePath.toUtf8(),"caches");
    MarkDownCache *cache=new MarkDownCache;
    cache->setContent(this->markdown->toPlainText());
    cache->setDate(QDateTime::currentDateTime());
    cache->setTitle(this->fileDefaultPath);
    data->addData<MarkDownCache>(cache);
    timer->stop();
}

QString MarkDown::getTitle()
{
    return cutTitle(title);
}

/**
 * 设置标题，当文件名发生改变时对标题进行更改
 * @brief MarkDown::setTitle
 * @param value
 */
void MarkDown::setTitle(const QString &value)
{
        title =cutTitle(value);
        ui->titleLab->setText(title);
}
/**
 * 保存文件，若默认路径存在，则将文件保存在默认路径下.
 * 当文件对话框出现后没有选择文件时，fileDefaultPath不被重新赋值
*/
QString MarkDown::saveFile()
{
    QString content=this->markdown->toPlainText();

    fileDefaultPath=manager->save(fileDefaultPath,markdown->getImageBtns(),content);
    setTitle(fileDefaultPath);
    return fileDefaultPath;
}


/**
 * 对过长的标题进行裁剪
*/
QString MarkDown::cutTitle(const QString &title)
{
    if(title.length()>25){
        return title.mid(0,7)+"......"+title.mid(title.length()-12,title.length());
    }
    return title;
}


void MarkDown::createActions()
{
    QAction *action=new QAction();
    action->setShortcut(QKeySequence(tr("Ctrl+S")));
    ui->saveBtn->addAction(action);
    connect(action,SIGNAL(triggered(bool)),ui->saveBtn,SLOT(click()));
}

void MarkDown::loadCache()
{
    JsonData *data=new JsonData(this->cachePath.toUtf8(),"caches");
    MarkDownCache *cache=data->selectById<MarkDownCache>(data->autoId());
    if(NULL!=cache)
    {
        this->markdown->setText(cache->content());
        markdown->refreshFormat();
        this->setTitle(cache->title());
        this->fileDefaultPath=cache->title();
    }
}

QString MarkDown::getCachePath() const
{
    return cachePath;
}

void MarkDown::setCachePath(const QString &value)
{
    cachePath = value;
    //    loadCache();
}
/**
 * @brief MarkDown::createFormat
 * 初始化markdownedit组件
 */
void MarkDown::createFormat()
{
    markdown=new MarkDownEdit(this);
    markdown->setTheme(MarkDownEdit::DARK);
    markdown->setFixedWidth(this->minimumWidth());
    markdown->setDefaultPath(this->cachePath);
    this->markdown->setFont(this->font());
    markdown->refreshFormat();
    connect(markdown,SIGNAL(textChanged()),this,SLOT(on_text_changed()));

}



void MarkDown::setUploadWidget(UploadDialog *value)
{
    uploadWidget = value;
}

void MarkDown::createControlIcon(QStringList icons)
{
    ui->shareBtn->setIcon(QIcon(icons.at(0)));
    ui->newBtn->setIcon(QIcon(icons.at(1)));
    ui->fileBtn->setIcon(QIcon(icons.at(2)));
    ui->saveBtn->setIcon(QIcon(icons.at(3)));
    ui->saveOtherBtn->setIcon(QIcon(icons.at(4)));
    ui->tipBtn->setIcon(QIcon(icons.at(5)));
}

void MarkDown::resizeEvent(QResizeEvent *event)
{
    ui->frame->setGeometry(0,this->height()-ui->frame->height(),
                           this->width(),
                           ui->frame->height());

    ui->frame_2->setGeometry(0,0,
                             this->width(),this->height()-ui->frame->height());
    this->uploadWidget->setGeometry(ui->shareBtn->x()-this->uploadWidget->getDelay(),
                                    ui->frame->y()-this->uploadWidget->height(),
                                    this->uploadWidget->width(),
                                    this->uploadWidget->height());

    this->markdown->setGeometry(this->width()/2-this->markdown->width()/2,
                                0,
                                this->markdown->width(),
                                ui->frame_2->height());
    ui->frame->raise();
}

void MarkDown::createDailyStyle()
{

}

void MarkDown::createDarkStyle()
{

}


/**
 * @brief MarkDown::on_newBtn_clicked
 * 创建新的markdown文件
 */
void MarkDown::on_newBtn_clicked()
{
    //提示是否保存当前文件

    //清空默认入境
    this->fileDefaultPath="";
    //清空编辑器中的内容
    this->markdown->clearContent();
 //   this->markdown->setText("");
    markdown->refreshFormat();
}
/**
 * @brief MarkDown::on_saveOtherBtn_clicked
 * 保存文件至其他位置
 */
void MarkDown::on_saveOtherBtn_clicked()
{
    this->fileDefaultPath="";
    saveFile();
}


