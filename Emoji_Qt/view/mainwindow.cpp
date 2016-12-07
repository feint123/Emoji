#include "buttonitem.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QSplitter>
#include <QDebug>
#include <QFileDialog>

#include <widget/view/listview.h>

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
    QList<QVariant> stringL;
    stringL<<"Heelo"<<"world"<<"welcome";
    ListView *view=new ListView();
    view->setData(stringL);
    ButtonItem *item=new ButtonItem;
    view->setItem(item);
    //this->imageSpli->addWidget(this->imageP);
    this->imageSpli->addWidget(view);
    this->imageSpli->addWidget(this->fileP);

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
