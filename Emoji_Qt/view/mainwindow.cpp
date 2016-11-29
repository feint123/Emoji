#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QSplitter>

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
    this->mainSpli->addWidget(this->toolP);

    this->imageSpli->addWidget(this->imageP);
    this->imageSpli->addWidget(this->fileP);

    this->imageSpli->setStretchFactor(0,5);
    this->imageSpli->setStretchFactor(1,1);

    this->setCentralWidget(this->mainSpli);
}

void MainWindow::initSubParts()
{
    this->toolP=new ToolPart(this);
    this->imageP=new ImagePart(this);
    this->fileP=new FilePart(this);
}
