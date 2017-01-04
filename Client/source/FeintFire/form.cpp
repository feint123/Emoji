
#include "form.h"
#include "ui_form.h"



#include <widget/view/listview.h>

#include <pane/markdown/markdownedit.h>

#include <fileload/articaluploaddialog.h>

#include <artical/articalhot.h>


#include <QGraphicsRectItem>

#include <plan/plancard.h>
#include <plan/plandialog.h>
#include <plan/planframe.h>

#include <widget/frame/transframe.h>

#include <domain/request/normalloginrequest.h>
#include <domain/request/request.h>

#include <util/json/objecttojson.h>

#include <QDebug>

#include <user/settingdialog.h>

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

//    edit->setTheme(MarkDownEdit::DARK);

//    ui->verticalLayout->addWidget(edit);


//    QStringList typeList;
//    typeList<<"Java"<<"PhP"<<"Javascript"<<"C"<<"C++"<<"问答";
//    ArticalUploadDialog *upload=new ArticalUploadDialog();
//    upload->setTypeList(typeList);
//    upload->show();
//    for(int i=0;i<=10;i++){
//        ArticalHot *hot=new ArticalHot;
//        hot->setHot(i/10.0);
//        ui->verticalLayout->addWidget(hot);
//    }
//    ui->textEdit->setText(tr("<img src=\"%1\">").arg("/Users/feint/Pictures/素材/灯泡.png"));
//    PlanFrame *plan=new PlanFrame;
//    ui->verticalLayout->addWidget(plan);


//    QGraphicsScene *scene=new QGraphicsScene;
//    scene->addRect(QRectF(0,0,100,100));
//    scene->addLine(10,10,150,300);
//    ui->graphicsView->setScene(scene);

//    PlanFrame *frame=new PlanFrame;
//    ui->verticalLayout->addWidget(frame);

//    PlanDialog *planD=new PlanDialog();
//    planD->show();

//    Request *request=new Request;
//    request->setToken("saftwegeagas");
//    NormalLoginRequest *normal=new NormalLoginRequest;
//    normal->setAcount("feint");
//    normal->setMac("1212:21312");
//    normal->setPwd("21234");
//    request->setData(QVariant::fromValue(normal));
//    ui->textEdit->setText(ObjectToJson::create(request).toJson());

    SettingDialog *setting=new SettingDialog;
    setting->show();
}

Form::~Form()
{
    delete ui;
}

