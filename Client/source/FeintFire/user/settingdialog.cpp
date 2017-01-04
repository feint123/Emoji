#include "settingdialog.h"
#include "settinghelper.h"
#include "ui_settingdialog.h"

#include <QDir>
#include <QFileSystemWatcher>
#include <QJsonDocument>

#include <domain/app/setting.h>

#include <util/json/jsontoobject.h>
#include <QJsonObject>

#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    loadSetting();
}


SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::loadSetting()
{
        doc=SettingHelper::readSetting();
        Setting *set=feint::JsonToObject::createObject<Setting>(doc.object());
        createView(set);
}

void SettingDialog::createView(Setting *set)
{
    ui->workEdit->setText(set->workspacing());
    ui->cacheEdit->setText(set->cache_area());


    ui->fontSpin->setValue(set->font_size());
    ui->workTog->setChecked(true);

    setToggle(ui->styleTog,(set->auto_style()==1?true:false));
    setToggle(ui->cacheTog,(set->cacheable()==1?true:false));
    setToggle(ui->workTog,(set->defaultable()==1?true:false));
    if(set->style()=="daily")
        ui->dailyRadio->setChecked(true);
    else
        ui->darkRadio->setChecked(true);
}

void SettingDialog::setToggle(FToogleButton *tog,bool checked)
{
    if(tog->isChecked()==checked)
        tog->setChecked(!checked);
    tog->setChecked(checked);
}

void SettingDialog::createDailyStyle()
{

}

void SettingDialog::createDarkStyle()
{

}

void SettingDialog::on_styleTog_toggled(bool checked)
{
    if(checked)
        ui->styleLab->setText("开");
    else
        ui->styleLab->setText("关");
}

void SettingDialog::on_cacheTog_toggled(bool checked)
{
    if(checked)
        ui->cacheLab->setText("开");
    else
        ui->cacheLab->setText("关");
}

void SettingDialog::on_workTog_toggled(bool checked)
{
    if(checked)
        ui->workLab->setText("开");
    else
        ui->workLab->setText("关");
}

/**
 * @brief SettingDialog::on_fButton_3_clicked
 * 保存已经修改地设置选项
 */
void SettingDialog::on_fButton_3_clicked()
{

    QJsonObject obj=doc.object();
    obj["font_size"]=ui->fontSpin->value();
    obj["font_family"]=ui->fontComboBox->currentText();
    obj["style"]=ui->dailyRadio->isChecked()?"daily":"dark";
    obj["cache_area"]=ui->cacheEdit->text();
    obj["cacheable"]=ui->cacheTog->isChecked()?1:0;
    obj["defaultable"]=ui->workTog->isChecked()?1:0;
    obj["workspacing"]=ui->workEdit->text();
    obj["auto_style"]=ui->styleTog->isChecked()?1:0;
    doc.setObject(obj);

    SettingHelper::saveSetting(doc);

}
