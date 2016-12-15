#include "carditem.h"
#include "form.h"
#include "ui_form.h"

#include <domain/articalcard.h>

#include <widget/view/listview.h>

#include <pane/markdown/markdownedit.h>

#include <fileload/articaluploaddialog.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
//    QList<QVariant> cardList;
//    ArticalCard card;
//    card.setTname("feint");
//    card.setTip("ewrjqegjoqegjqeogz林卡是否健康啦");
//    cardList.append(QVariant::fromValue(card));
//    cardList.append(QVariant::fromValue(card));
//    cardList.append(QVariant::fromValue(card));
//    cardList.append(QVariant::fromValue(card));
//    ListView *listView=new ListView();
//    listView->setItemSpacing(16);
//    listView->setData(cardList);
//    CardItem *item=new CardItem;
//    listView->setItem(item);
//    ui->horizontalLayout->addWidget(listView);



//    MarkDownEdit *edit=new MarkDownEdit(this);

//    ui->horizontalLayout->addWidget(edit);


    QStringList typeList;
    typeList<<"Java"<<"PhP"<<"Javascript"<<"C"<<"C++"<<"问答";
    ArticalUploadDialog *upload=new ArticalUploadDialog();
    upload->setTypeList(typeList);
    upload->show();

}

Form::~Form()
{
    delete ui;
}
