#include "plandialog.h"
#include "ui_plandialog.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QPainter>
#include <user/settinghelper.h>
#include <util/graphic/innerdialogrect.h>
#include <util/json/jsondata.h>
#include <util/json/objecttojson.h>


PlanDialog::PlanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanDialog)
{
    ui->setupUi(this);
//    QPalette pal = palette();
//    pal.setColor(QPalette::Background, QColor(0xd7,0xd7,0xd7,0xcc));
//    setPalette(pal);
    tri=12;
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->levelComb->addItems(PlanDialog::createLevel());
    ui->startDate->setDateTime(QDateTime::currentDateTime());
    ui->endDate->setDateTime(QDateTime::currentDateTime());
    plan=new Plan();
    this->installFilter();
}

QStringList PlanDialog::createLevel()
{
    QStringList list;
    list<<"休闲"<<"普通"<<"急迫"<<"紧急";
    return list;
}

QHash<QString, QString> PlanDialog::createType()
{
    QHash<QString,QString> typeColor;
    typeColor["日常生活"]=tr("#ccc");
    typeColor["娱乐"]=tr("#f79f1f");
    typeColor["工作"]=tr("#1b7cff");
    typeColor["学习"]=tr("#d90d0d");
    typeColor["旅游"]=tr("#3ab155");
    return typeColor;
}

PlanDialog::~PlanDialog()
{
    delete ui;
}

void PlanDialog::on_okBtn_clicked()
{
    plan->setTitle(ui->titleEdit->text());
    plan->setLevel(ui->levelComb->currentIndex()+1);
    plan->setStartDate(ui->startDate->dateTime());
    plan->setEndDate(ui->endDate->dateTime());
    plan->setContent(ui->contentText->toPlainText());
    JsonData *data=new JsonData((SettingHelper::workingPath()+tr("/plan.json")).toUtf8(),"plans");
    data->addData<Plan>(plan);

}

void PlanDialog::on_cancelBtn_clicked()
{
    this->close();
}

void PlanDialog::installFilter()
{
   ui->dailyCircle->installEventFilter(this);
   ui->workCircle->installEventFilter(this);
   ui->studyCircle->installEventFilter(this);
   ui->playCircle->installEventFilter(this);
   ui->travelCircle->installEventFilter(this);
}

int PlanDialog::getTri() const
{
    return tri;
}

int PlanDialog::getTriPlace() const
{
    return triPlace;
}

void PlanDialog::setTriPlace(int value)
{
    triPlace = value;
}


bool PlanDialog::eventFilter(QObject *watched, QEvent *event)
{

    if(event->type()==QEvent::MouseButtonPress)
    {
        if(watched->metaObject()==ui->playCircle->metaObject())
        {
            ui->showBtn->setBgColor(((FCircle*)watched)->color());
            plan->setType(((FCircle*)watched)->flag());
        }
    }
}

void PlanDialog::paintEvent(QPaintEvent *event)
{
    InnerDialogRect *inner=new InnerDialogRect(InnerDialogRect::RIGHT);
    inner->setTri(this->tri);
    inner->draw(this,this->triPlace);
}
