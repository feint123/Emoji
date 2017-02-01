#include "notetool.h"
#include "ui_notetool.h"

#include <util/appcolorhelper.h>
#include <util/qvariantutil.h>
#include <util/screenfit.h>

#include <plug/appstatic.h>

#include <domain/wordstatic.h>

#include <view/note/markpull/markdownhotkey.h>
#include <view/note/markpull/markfactory.h>
#include <view/note/markpull/markitem.h>
#include <QAction>
#include <action/markdownquick.h>

NoteTool::NoteTool(QWidget *parent) :
    BaseTool(parent),
    ui(new Ui::NoteTool)
{
    ui->setupUi(this);

  //  createMarkPull();
    action=new NoteAction(this);

    connect(ui->newBookBtn,SIGNAL(clicked(bool)),action,SLOT(addNote()));
    connect(this,SIGNAL(outNote(QString)),action,SLOT(outNote(QString)));

    ui->newBookBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->outBookBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->readBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));

    ScreenFit::fitFont(ui->newBookBtn);
    ScreenFit::fitFont(ui->outBookBtn);
    ScreenFit::fitFont(ui->readBtn);

    ui->newBookBtn->setText(WordStatic::new_+WordStatic::note);
    ui->outBookBtn->setText(WordStatic::out+WordStatic::note);
    ui->readBtn->setText(WordStatic::read);



    QMargins m=this->contentsMargins();
    setContentsMargins(m.left(),m.top(),ScreenFit::fitToScreen(32),m.bottom());
}

NoteTool::~NoteTool()
{
    delete ui;
}

void NoteTool::on_outBookBtn_clicked()
{
    outNote(AppStatic::currentNote);
}

void NoteTool::on_quick_choosed(QVariant data)
{
    MarkdownHotKey key=qvariant_cast<MarkdownHotKey>(data);
    switch (key.key()) {
    case 0:
        emit addHeader1();
        break;
    case 1:
        emit addHeader2();
        break;
    case 2:
        emit addHeader3();
        break;
    case 3:
        emit addHeader4();
        break;
    case 4:
        emit addHeader5();
        break;
    case 5:
        emit addHeader6();
        break;
    case 6:
        emit addBlod();
        break;
    case 7:
        emit addItalic();
        break;
    case 8:
        emit addCode();
        break;
    case 9:
        emit addDelete();
        break;
    case 10:
        emit addDevide();
        break;
    case 11:
        emit addOrderList();
        break;
    case 12:
        emit addUnOrderList();
            break;
    case 13:
        emit addBlock();
        break;
    case 14:
        emit insertImage();
        break;
    case 15:
        emit zoomInEdit();
        break;
    case 16:
        emit zoomOutEdit();

    default:
        break;
    }
}

void NoteTool::connectToQuick(MarkDownQuick *quick)
{
    connect(this,SIGNAL(addHeader1()),quick,SLOT(addHeader1()));
    connect(this,SIGNAL(addHeader2()),quick,SLOT(addHeader2()));
    connect(this,SIGNAL(addHeader3()),quick,SLOT(addHeader3()));
    connect(this,SIGNAL(addHeader4()),quick,SLOT(addHeader4()));
    connect(this,SIGNAL(addHeader5()),quick,SLOT(addHeader5()));
    connect(this,SIGNAL(addHeader6()),quick,SLOT(addHeader6()));
    connect(this,SIGNAL(addBlock()),quick,SLOT(addBlock()));
    connect(this,SIGNAL(addBlod()),quick,SLOT(addBlod()));
    connect(this,SIGNAL(addCode()),quick,SLOT(addCode()));
    connect(this,SIGNAL(addDelete()),quick,SLOT(addDelete()));
    connect(this,SIGNAL(addDevide()),quick,SLOT(addDevide()));
    connect(this,SIGNAL(addItalic()),quick,SLOT(addItalic()));
    connect(this,SIGNAL(addOrderList()),quick,SLOT(addOrderList()));
    connect(this,SIGNAL(addUnOrderList()),quick,SLOT(addUnOrderList()));
    connect(this,SIGNAL(zoomInEdit()),quick,SLOT(zoomInEdit()));
    connect(this,SIGNAL(zoomOutEdit()),quick,SLOT(zoomOutEdit()));
    connect(this,SIGNAL(insertImage()),quick,SLOT(insertImage()));
}

void NoteTool::createMarkPull()
{
    if(!firstPull)
        return;
    firstPull=false;
    QList<MarkdownHotKey*> hotKeys;
    int i=0;
    MarkDownQuick *quick=MarkDownQuick::getInstance();
    connectToQuick(quick);
    for(QAction *ac:quick->getActionList())
    {
        MarkdownHotKey *hot=new MarkdownHotKey;
        hot->setKey(i);
        hot->setValue(ac->text());
        hotKeys.append(hot);
        i++;
    }

    MarkItem *mItem=new MarkItem(ui->pull);
    mItem->setText(WordStatic::markLab);
//    mItem->resize(100,24);
    ui->pull->setItem(mItem);
    ui->pull->setWidgetFactory(MarkFactory::create);
    ui->pull->setListData(QVariantUtil::turn<MarkdownHotKey>(hotKeys));
    ui->pull->setFixedSize(ScreenFit::fitToScreen(150),
                           ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ScreenFit::fitWithFont(ui->pull);
    connect(ui->pull,SIGNAL(listItemSelect(QVariant)),this,SLOT(on_quick_choosed(QVariant)));
}
