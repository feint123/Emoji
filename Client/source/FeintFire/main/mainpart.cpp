
#include "maincontent.h"
#include "mainpart.h"
#include "ui_mainpart.h"
#include <QDebug>
//QTabWidget::tab-bar{\n	alignment:left;\n}\nQTabBar::tab{\n	border-bottom:3px solid #eee;\n	min-height:32px;\n	min-width:80px;\n	background:#0076FF;\n	color:white;\n}\n

MainPart::MainPart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPart)
{
    flag=true;
    ui->setupUi(this);

    tabWidget=new QTabWidget;
    ui->frame->layout()->addWidget(tabWidget);

    baseStyle=tr("QTabWidget::tab-bar{alignment:center;}"
             "QTabBar::tab{border-bottom:3px solid %1;min-height:32px;min-width:80px;background:%1;color:%2;}"
             "QTabBar::tab:selected{border-bottom:3px solid #25619d;}"
                 "#frame{background:%1}");

    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(focusTab(int)));
}

MainPart::~MainPart()
{
    flag=false;
    delete ui;
}
/**
 * @brief MainPart::addTabs
 * @param tabs
 * 初始化选项卡
 */
void MainPart::addTabs(QStringList tabs)
{
    foreach(QString tabTitle,tabs)
    {
        MainContent *mainC=new MainContent();
        mainC->setColorStyle(this->getColorStyle());
        this->tabWidget->addTab(mainC,tabTitle);
        connect(mainC,SIGNAL(selectTid(int)),this->parent(),SLOT(loadArtical(int)));
    }
}

void MainPart::focusTab(int n)
{
    ((MainContent*)this->tabWidget->currentWidget())->refresh(tabWidget->tabText(n));
}

void MainPart::createDailyStyle()
{
    QString currentStyle=this->baseStyle.arg("#d7d7d7").arg("#252526");
    this->setStyleSheet(currentStyle);
}

void MainPart::createDarkStyle()
{
    QString currentStyle=this->baseStyle.arg("#252526").arg("#d7d7d7");
    this->setStyleSheet(currentStyle);
}



