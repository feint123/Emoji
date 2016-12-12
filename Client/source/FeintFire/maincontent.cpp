#include "carditem.h"
#include "maincontent.h"
#include "ui_maincontent.h"

#include <domain/articalcard.h>
#include <QDebug>

MainContent::MainContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainContent)
{
    ui->setupUi(this);
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
    CardItem *cardItem=new CardItem;
    listView->setItem(cardItem);

    ui->verticalLayout->takeAt(0);
    ui->verticalLayout->addWidget(listView);

    connect(listView,SIGNAL(selectItemIndex(int)),this,SLOT(getTid(int)));
    return listView;
}

void MainContent::getTid(int id)
{
    qDebug()<<"MainContent[getTid]:"<<id;
    ArticalCard card=qvariant_cast<ArticalCard>(this->cardList.at(id));
    emit selectTid(card.getTid());
}

