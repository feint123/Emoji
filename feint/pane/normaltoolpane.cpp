#include "normaltoolpane.h"
#include "showpane.h"
#include "ui_normaltoolpane.h"
#include <domain/setting/textsetting.h>

#include <util/xml/settingtextanalysis.h>
#include <util/xml/xmlanalysis.h>

NormalToolPane::NormalToolPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalToolPane)
{
    ui->setupUi(this);
    ui->hightColor->hide();
}

NormalToolPane::~NormalToolPane()
{
    delete ui;
}

void NormalToolPane::initTextColor()
{
    XmlAnalysis *analy=new SettingTextAnalysis();
    TextSetting *text=(TextSetting*)analy->analysis(&doc);
    ui->firstmenuText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::FIRSTMENU)));
    ui->secondmenuText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::SECONDMENU)));
    ui->typeText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::TYPE)));
    ui->maintitleText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::MAINTILE)));
    ui->tagText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::TAG)));
    ui->tipText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::TIP)));
    ui->otherText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::OTHER)));
    ui->artiInfoText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::ARTICAL_INFO)));
    ui->artiTextText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::ARTICAL_TEXT)));
    ui->artiTitleText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::ARTICAL_TITLE)));
    ui->comInfoText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::COMMENT_INFO)));
    ui->comNameText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::NAME)));
    ui->comTextText->setCurrentColor(text->getColor(text->getTextType(TextSetting::Textype::COMMENT_TEXT)));
}

void NormalToolPane::initBackgroundColor()
{

}

void NormalToolPane::on_pushDownBtn_clicked()
{
    ui->hightColor->show();
    QFile file("/Users/feint/Documents/XML/color.xml");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        doc.setContent(&file);
    initTextColor();
    initBackgroundColor();
    ShowPane *showPane=new ShowPane();
    showPane->show();
}

void NormalToolPane::on_pushUpBtn_clicked()
{
    ui->hightColor->hide();
}
