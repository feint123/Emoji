#include "plancard.h"
#include "plandialog.h"
#include "planframe.h"
#include "ui_planframe.h"

#include <widget/frame/fscaleframe.h>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPainter>
#include <QPushButton>
#include <QScrollArea>
#include <QTimer>
#include <fbutton.h>
#include <util/json/jsondata.h>
#include <util/json/jsontoobject.h>
#include <user/settinghelper.h>
#include <util/graphic/effectutil.h>

PlanFrame::PlanFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlanFrame)
{
    ui->setupUi(this);
 //   EffectUtil::addOpacity(0.8,ui->frame);
    planDialog=new PlanDialog(this);
 //   planDialog->setAutoFillBackground(true);
    planDialog->setWindowFlags(Qt::FramelessWindowHint);
    planDialog->setTriPlace(32+25);
    planDialog->hide();


    planPath=tr("%1/plan.json").arg(SettingHelper::workingPath());
    data=new JsonData(planPath.toUtf8(),"plans");
    this->createCardList(data->selectAll<Plan>());

    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(planPath);
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(refresh()));


    initLayout();
    setLineNum(2);
}

PlanFrame::~PlanFrame()
{
    delete ui;
}

int PlanFrame::lineNum() const
{
    return m_lineNum;
}

void PlanFrame::setLineNum(int lineNum)
{
    if (m_lineNum == lineNum)
        return;

    m_lineNum = lineNum;
    emit lineNumChanged(lineNum);
}

void PlanFrame::addPlan(Plan* plan)
{
        PlanCard *card=new PlanCard;
        card->setTitle(plan->title());
        card->setContent(plan->content());
        QString dateFormat="yyyy/MM/dd";
        QString time=plan->startDate().toString(dateFormat)+tr("~")+
                plan->endDate().toString(dateFormat);
        card->setTime(time);
        card->setCircleColor(PlanDialog::createType()[plan->type()]);
        card->setTypeTip(plan->type());
        card->setId(plan->id());
        connect(card,SIGNAL(deleteCard(int)),this,SLOT(deletePlanById(int)));
        this->cardList.append(card);
}



void PlanFrame::initLayout()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(refreshItems()));
    vb=new QVBoxLayout();
    grid=new QGridLayout();
    grid->setSpacing(32);
    vb->addLayout(grid);
    vb->addStretch(0);
    ui->scrollArea->widget()->setLayout(vb);
}

void PlanFrame::refreshItems()
{
    //清除布局中控件的标准方式
    QLayoutItem *child;
    while(child=grid->takeAt(0)) {
       // child->widget()->hide();
        delete child;
    }

    for(int i=0;i<cardList.count();i++)
    {
        this->grid->addWidget(cardList.at(i),i/lineNum(),i%lineNum());
    }
    timer->stop();

}

void PlanFrame::resizeEvent(QResizeEvent *event)
{
    int width=this->width()-(lineNum())*grid->spacing();
    int count=(width>=240?width:240)/240;
    setLineNum(count>cardList.count()?cardList.count():count);
    if(!timer->isActive())
    {
        timer->setInterval(500);
        timer->start();
    }
    int margin=32;
    ui->scrollArea->setGeometry(0,0,this->geometry().width(),this->geometry().height());
    ui->fButton->setGeometry(this->geometry().width()-ui->fButton->width()-margin,
                             this->geometry().height()-ui->fButton->height()-margin,
                             ui->fButton->width(),ui->fButton->height());
    ui->sortBtn->setGeometry(this->geometry().width()-ui->fButton->width()-margin,
                             this->geometry().height()-2*(ui->fButton->height())-margin*3/2,
                             ui->fButton->width(),ui->fButton->height());

    planDialog->setGeometry(ui->fButton->x()-planDialog->width(),
                            ui->fButton->y()-planDialog->height()+
                            (ui->fButton->height()+planDialog->getTriPlace())/2,
                            planDialog->width(),planDialog->height());
}


void PlanFrame::createCardList(QList<Plan *> planList)
{
    for(PlanCard *card:cardList)
        delete card;
    this->cardList.clear();   
    for(Plan *plan:planList){
        addPlan(plan);
    }
}

void PlanFrame::createDailyStyle()
{

}

void PlanFrame::createDarkStyle()
{

}


/**
 * @brief PlanFrame::on_fButton_clicked
 * 添加新计划
 */
void PlanFrame::on_fButton_clicked()
{
    planDialog->show();
}

void PlanFrame::refresh()
{
    this->createCardList(data->selectAll<Plan>());
    if(!timer->isActive())
    {
        timer->setInterval(100);
        timer->start();
    }
    ui->scrollArea->update();
}

void PlanFrame::deletePlanById(int id)
{
    data->deleteData(id);
}
