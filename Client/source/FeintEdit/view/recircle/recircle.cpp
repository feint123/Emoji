#include "lastedititem.h"
#include "recircle.h"
#include "recircleitem.h"

#include <qpainter.h>
#include <QDebug>

#include <util/graphic/animationutil.h>
#include <util/graphic/effectutil.h>

#include <util/appcolorhelper.h>
#include <util/qvariantutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>

#include <util/json/jsondata.h>

#include <domain/appmessage.h>
#include <domain/lastedit.h>
#include <domain/recirclepage.h>
#include <domain/wordstatic.h>

#include <widget/view/listviewbeauti.h>

#include <plug/appstatic.h>
Recircle::Recircle(QWidget *parent):
    QFrame(parent)
{
    createHeader();
    headerH=ScreenFit::fitToScreen(AppStatic::toolHeight);
}

void Recircle::setImg(const QImage &value)
{
    img = value;
}

void Recircle::refreshList()
{
    list=new ListView(this);
    AppColor *color=AppColorHelper::loadColor();
    list->setScrollHandle(color->scrollHandle());
    list->setScrollPage(color->scrollPage());
    list->createView();
    list->setSpacing(ScreenFit::fitToScreen(16));
    list->setMargin(QMargins(0,ScreenFit::fitToScreen(32),
                             0,ScreenFit::fitToScreen(32)));
    list->setSelectStyle(tr(""));
    list->setUnSelectStyle(tr(""));
    list->setBgColor(Qt::transparent);
    list->setBg(ListViewBeauti::colorBackground);
    list->setItem(new RecircleItem());
    updateRecircleIndex(AppStatic::recircleIndex);
    list->setGeometry(0,header->height(),this->width(),
                      this->height()-headerH);
    header->setGeometry(0,0,this->width(),headerH);
}

void Recircle::updateRecircleIndex(int i)
{

    AppStatic::recircleIndex=i;
    switch(i){
    case 3:
        updateListData(AppMessage::RECIRCLE);
        break;
    case 0:
        updateListData(AppMessage::LASTEDIT);
        break;
    }
}

void Recircle::animBack()
{
    updateListData();
    AnimationUtil::GeometryAnim(end,start,list,250);

}

void Recircle::createHeader()
{
    header=new RecircleHeader(this);

    header->addItem(WordStatic::last+WordStatic::edit);
    header->addItem(WordStatic::collect);
    header->addItem(WordStatic::message);
    header->addItem(WordStatic::recircle);
    header->createView(AppStatic::recircleIndex);
    connect(header,SIGNAL(itemClicked(int)),this,SLOT(updateRecircleIndex(int)));
}

void Recircle::updateListData(AppMessage::TYPE type)
{
    this->type=type;
    if(!firstShow){
        listDataChangeAnimation();
    }else{
        firstShow=false;
        updateListData();
    }
}

void Recircle::setFirstShow(bool value)
{
    firstShow = value;
}

void Recircle::listDataChangeAnimation()
{
    start=list->geometry();
    end=QRect(list->width()+list->x(),list->y(),
                    list->width(),list->height());
    QPropertyAnimation *anim= AnimationUtil::GeometryAnim(start,end,list,250);
    connect(anim,SIGNAL(finished()),this,SLOT(animBack()));
}

void Recircle::updateListData()
{
    JsonData *data=new JsonData(SettingHelper::workPath(AppMessage::getFileName(type)+".json").toUtf8()
                              ,AppMessage::getFileName(type));
    QVariantUtil *util=new QVariantUtil;

    switch(type){
    case AppMessage::RECIRCLE:
        list->setItem(new RecircleItem());
        list->addData(util->turn<RecirclePage>(data->selectAll<RecirclePage>()));
        break;
    case AppMessage::LASTEDIT:
        list->setItem(new LastEditItem());
        list->addData(util->turn<LastEdit>(data->desc<LastEdit>(data->selectAll<LastEdit>())));
        break;
    }
}

void Recircle::paintEvent(QPaintEvent *event)
{
    QImage temp;
    QPainter painter(this);
    QMatrix matrix;
    matrix.scale(this->width()/(float)img.width(),
                 this->height()/(float)img.height());
    temp=img.transformed(matrix);
    painter.drawImage(0,0,temp);

}

void Recircle::resizeEvent(QResizeEvent *event)
{

    header->setGeometry(0,0,this->width(),headerH);
    list->setGeometry(0,header->height(),this->width(),
                      this->height()-headerH);
}
