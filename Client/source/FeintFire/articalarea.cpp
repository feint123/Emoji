#include "articalarea.h"
#include "ui_articalarea.h"

#include <net/articalfactory.h>

ArticalArea::ArticalArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticalArea)
{
    ui->setupUi(this);
}

ArticalArea::~ArticalArea()
{
    delete ui;
}

void ArticalArea::load(int articalId)
{
    ArticalFactory *factory=new ArticalFactory();
    factory->refreshArtical(articalId);
    connect(factory,SIGNAL(createArtical(Artical*)),this,SLOT(loadArtical(Artical*)));
}

void ArticalArea::loadArtical(Artical *artical)
{
    ui->titleLab->setText(artical->getTitle());
    ui->content->setText(artical->getContent());
    ui->writerLab->setText(artical->getInfo().getName());
    ui->readCountLab->setText(QString::number(artical->getInfo().getRead()));
    if(artical->getInfo().getSupported()==1)
        ui->supportBtn->setText("取消赞");
    else
        ui->supportBtn->setText("赞");

    if(artical->getInfo().getCollected()==1)
        ui->collectBtn->setText("取消收藏");
    else
        ui->collectBtn->setText("收藏");
}
