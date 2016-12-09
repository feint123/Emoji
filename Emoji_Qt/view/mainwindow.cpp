#include "buttonitem.h"
#include "cardshow.h"
#include "mainwindow.h"
#include "shadowbutton.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QSplitter>
#include <QDebug>
#include <QFileDialog>

#include <widget/view/listview.h>

#include <domain/card.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSubParts();
    initSplitter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCard(QVariant card)
{
    CardShow *show=new CardShow(qvariant_cast<Card>(card));
    show->show();
}



void MainWindow::initSplitter()
{
    this->mainSpli=new QSplitter(this);
    this->imageSpli=new QSplitter(mainSpli);
    this->mainSpli->setOrientation(Qt::Horizontal);
    this->imageSpli->setOrientation(Qt::Vertical);

    this->mainSpli->setStretchFactor(0,5);
    this->mainSpli->setStretchFactor(1,1);

    this->mainSpli->addWidget(this->imageSpli);
//    this->mainSpli->addWidget(this->toolP);
    this->mainSpli->addWidget(this->normalP);


    /** 测试listview的显示效果**/
    QList<QVariant> stringL;
    Card card;
    card.setDate(QDate::currentDate());
    card.setTname("QT学习");
    card.setTip("2013年1月28日 - 这些在 Qt 5 中也是类似的,但是如果你通过使用 Q_DECLARE_METATYPE 宏,\n将一个 QObject 子类的指针保存到 QVariant 时,你会 得到一个编译错误(Qt 4 中...");
    card.setHot(10.5);
    stringL.append(QVariant::fromValue(card));
    card.setDate(QDate::currentDate());
    card.setTname("QT学习");
    card.setTip("Starting /Users/feint/Desktop/Emoji/build-Emoji_Qt-Desktop_Qt_5_7_0_clang_64bit-Debug/Emoji_Qt.app/Contents/MacOS/Emoji_Qt");
    card.setHot(10.5);
    stringL.append(QVariant::fromValue(card));
    stringL.append(QVariant::fromValue(card));
    stringL.append(QVariant::fromValue(card));
    ListView *view=new ListView();
    view->setData(stringL);
    view->setItemSpacing(16);
    ButtonItem *item=new ButtonItem;
    view->setItem(item);
    //this->imageSpli->addWidget(this->imageP);
    this->imageSpli->addWidget(view);
    connect(view,SIGNAL(selectItem(QVariant)),this,SLOT(showCard(QVariant)));


    /**测试阴影的添加效果**/
    ShadowButton *sbtn=new ShadowButton();
    sbtn->setText("ShadowTest");
    this->imageSpli->addWidget(sbtn);
  //  this->imageSpli->addWidget(this->fileP);


    this->imageSpli->setStretchFactor(0,5);
    this->imageSpli->setStretchFactor(1,2);

    this->setCentralWidget(this->mainSpli);
}

void MainWindow::initSubParts()
{
    this->toolP=new ToolPart(this);
    this->imageP=new ImagePart(this);
    this->fileP=new FilePart(this);
    this->normalP=new NormalToolPane();

    connect(toolP,SIGNAL(fontSizeChanged(int)),imageP->getEmojiLabel(),SLOT(setFontSize(int)));
    connect(toolP,SIGNAL(fontChanged(QFont)),imageP->getEmojiLabel(),SLOT(setFont(QFont)));

    connect(toolP,SIGNAL(zoomIn()),imageP,SLOT(zoomIn()));
    connect(toolP,SIGNAL(zoomOut()),imageP,SLOT(zoomOut()));

    connect(toolP,SIGNAL(colorChanged(int,ToolPart::ColorPart)),imageP,SLOT(changeColor(int,ToolPart::ColorPart)));

    connect(imageP->getEmojiLabel(),SIGNAL(editEmoji()),toolP,SLOT(editEnable()));
    connect(toolP,SIGNAL(emojiStringChanged(QString)),imageP->getEmojiLabel(),SLOT(setEmojiText(QString)));

    connect(toolP,SIGNAL(placeIdChanged(int,bool)),imageP->getEmojiLabel(),SLOT(placeText(int,bool)));

    connect(imageP->getEmojiLabel(),SIGNAL(currentEmojiTextChanged(EmojiText*)),toolP,SLOT(updateEdit(EmojiText*)));
}

void MainWindow::on_actionOpenFile_triggered()
{
    QString imagePath=QFileDialog::getOpenFileName(this,"获取图片","/",tr("图片格式(*.jpg *.jpeg *.png)"));
    this->imageP->setImagePath(imagePath);
    this->imageP->loadFile();
    this->toolP->restart();
    setWindowTitle(imagePath);

}
