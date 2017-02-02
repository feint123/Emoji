#include "appstatic.h"
#include "settingdialog.h"
#include "ui_settingdialog.h"

#include <view/tipdialog.h>

#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/wordhelper.h>

#include <QFileDialog>

#include <domain/wordstatic.h>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    createView();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
/**
 * @brief SettingDialog::on_fToogleButton_toggled
 * @param checked
 * 是否分享笔记中的图片
 */
void SettingDialog::on_fToogleButton_toggled(bool checked)
{
//    if(checked)
//        ui->shareImgLab->setText("开");
//    else
//        ui->shareImgLab->setText("关");
}

/**
 * @brief SettingDialog::on_submitBtn_clicked
 * 提交测试信息
 */
void SettingDialog::on_submitBtn_clicked()
{
    Setting *setting=SettingHelper::loadSetting();
    setting->setFontFamily(ui->fontComboBox->currentText());
    setting->setFontSize(ui->spinBox->value());
 //   setting->setIsShareImage(ui->fToogleButton->isChecked());
    setting->setWorkspacing(ui->defaultPathEdit->text());
    setting->setAutoSave(ui->spinBox_2->value());
    SettingHelper::saveSetting(setting);

    tip=createTip();
    tip->showTip();
}

TipDialog *SettingDialog::createTip()
{
    TipDialog *tip=TipDialog::getInstance(this);
    tip->setFontSize(ScreenFit::fitToScreen(SettingHelper::fontSize()+2));
    tip->setTip(WordStatic::tip_8);
    tip->setKeep(3500);
    tip->resize(tip->width(),ScreenFit::fitToScreen(60));
    return tip;
}

void SettingDialog::createView()
{
    Setting *setting=SettingHelper::setting();
 //   setToggled(ui->fToogleButton,setting->isShareImage()==1?true:false);
    ui->spinBox->setValue(setting->fontSize());
    ui->fontComboBox->setCurrentText(setting->fontFamily());
    ui->defaultPathEdit->setText(setting->workspacing());
    ui->spinBox_2->setValue(setting->autoSave());

    ScreenFit::fitFont(ui->defaultSaveLab);
    ScreenFit::fitFont(ui->dPlaceLab);
    ScreenFit::fitFont(ui->ffLab);
    ScreenFit::fitFont(ui->fileLab);
    ScreenFit::fitFont(ui->fontLab);
    ScreenFit::fitFont(ui->noteLab);
    ScreenFit::fitFont(ui->sizeLab);
    ScreenFit::fitFont(ui->secondLab);
    ui->spinBox->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->spinBox_2->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->fontComboBox->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->cancelBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->submitBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->defaultPathBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->defaultPathEdit->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ScreenFit::fitWithFont(ui->cancelBtn);
    ScreenFit::fitWithFont(ui->defaultPathBtn);
    ScreenFit::fitWithFont(ui->defaultPathEdit);
    ScreenFit::fitWithFont(ui->fontComboBox);
    ScreenFit::fitWithFont(ui->resetBtn);
    ScreenFit::fitWithFont(ui->submitBtn);
    ScreenFit::fitWithFont(ui->spinBox);
    ScreenFit::fitWithFont(ui->spinBox_2);
}

void SettingDialog::setToggled(FToogleButton *tog, bool checked)
{
    if(tog->isChecked()==checked)
        tog->setChecked(!checked);
    tog->setChecked(checked);
}

void SettingDialog::on_defaultPathBtn_clicked()
{
    QString fileDir=QFileDialog::getExistingDirectory(this,"Default Workspacing",QDir::currentPath());
    ui->defaultPathEdit->setText(fileDir);
}
