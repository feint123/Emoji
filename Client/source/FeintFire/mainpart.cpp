#include "carditem.h"
#include "maincontent.h"
#include "mainpart.h"
#include "ui_mainpart.h"
#include <QDebug>
#include <domain/articalcard.h>
//QTabWidget::tab-bar{\n	alignment:left;\n}\nQTabBar::tab{\n	border-bottom:3px solid #eee;\n	min-height:32px;\n	min-width:80px;\n	background:#0076FF;\n	color:white;\n}\n

MainPart::MainPart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPart)
{
    ui->setupUi(this);
    tabWidget=new QTabWidget;
    ui->horizontalLayout->addWidget(tabWidget);

    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(focusTab(int)));
}

MainPart::~MainPart()
{
    delete ui;
}

void MainPart::addTabs(QStringList tabs)
{
    foreach(QString tabTitle,tabs)
    {
        MainContent *mainC=new MainContent();
        this->tabWidget->addTab(mainC,tabTitle);
    }
}

void MainPart::focusTab(int n)
{
    ((MainContent*)this->tabWidget->currentWidget())->refresh(tabWidget->tabText(n));
}


