#include "carditem.h"
#include "maincontent.h"
#include "ui_maincontent.h"

#include <domain/articalcard.h>

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

    listView->setItemSpacing(16);
    listView->setData(cardList);
    CardItem *cardItem=new CardItem;
    listView->setItem(cardItem);

    ui->verticalLayout->takeAt(0);
    ui->verticalLayout->addWidget(listView);
    return listView;
}

