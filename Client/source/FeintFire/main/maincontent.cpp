
#include "maincontent.h"
#include "ui_maincontent.h"

#include <QDebug>
#include <domain/response/invitationcard.h>
#include <listview/carditem.h>

MainContent::MainContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainContent)
{
    ui->setupUi(this);
    baseStyle="#frame{border:none;background:%1}";
    factory=new InvitationFactory();
    connect(factory,SIGNAL(cardListLoadSuccess(QList<QVariant>)),this,SLOT(initCards(QList<QVariant>)));
}

MainContent::~MainContent()
{
    delete ui;
}

void MainContent::refresh(QString tabName)
{
    factory->requestCard(tabName);

}
ListView* MainContent::initCards(QList<QVariant> cardList)
{

    ListView *listView=new ListView();
  //  listView->setOrientation(ListView::Horizontal);
    this->cardList=cardList;
    listView->setItemSpacing(16);
    listView->setData(cardList);
    CardItem *cardItem=new CardItem(this->getColorStyle());
    listView->setItem(cardItem);
    listView->setColorStyle(this->getColorStyle());
    ui->verticalLayout->takeAt(0);
    ui->verticalLayout->addWidget(listView);

    connect(listView,SIGNAL(selectItemIndex(int)),this,SLOT(getTid(int)));
    return listView;
}

void MainContent::getTid(int id)
{
    qDebug()<<"MainContent[getTid]:"<<id;
    InvitationCard card=qvariant_cast<InvitationCard>(this->cardList.at(id));
    emit selectTid(card.tid());
}

void MainContent::createDailyStyle()
{
    ui->frame->setStyleSheet(baseStyle.arg("#f9f9f9"));
}

void MainContent::createDarkStyle()
{
    ui->frame->setStyleSheet(baseStyle.arg("#404244"));

}

