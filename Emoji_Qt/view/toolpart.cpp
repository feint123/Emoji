#include "toolpart.h"
#include "ui_toolpart.h"
#include <QDebug>

ToolPart::ToolPart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolPart)
{
    ui->setupUi(this);
    initImage();
    initText();
}

void ToolPart::restart()
{
    restartImage();
    restartText();
}

ToolPart::~ToolPart()
{
    delete ui;
}
void ToolPart::editEnable()
{
    ui->hotComb->setEnabled(true);
    ui->verComb->setEnabled(true);
    ui->horiComb->setEnabled(true);
    ui->sizeSpin->setEnabled(true);
    ui->colorLab->setEnabled(true);
    ui->fontComboBox->setEnabled(true);
}


void ToolPart::on_redSlider_sliderMoved(int position)
{
    ui->redPerLab->setText(QString("%1%").arg(position));
    setRed(position);
}

void ToolPart::on_greenSlider_sliderMoved(int position)
{
    ui->greenPerLab->setText(QString("%1%").arg(position));
    setGreen(position);
}

void ToolPart::on_blueSlider_sliderMoved(int position)
{
    ui->bluePerLab->setText(QString("%1%").arg(position));
    setBlue(position);
}

void ToolPart::initImage()
{
   initSlider(ui->redSlider);
   initSlider(ui->blueSlider);
   initSlider(ui->greenSlider);
   scale=1.0;
   ui->zoomIn->setEnabled(false);
   ui->zoomOut->setEnabled(false);
   ui->frame->hide();
   ui->frame_2->hide();
}

void ToolPart::initText()
{
    QStringList directList;
    directList<<"顶部"<<"中间"<<"底部";
    ui->verComb->addItems(directList);
    ui->horiComb->addItems(directList);

    QStringList hotList;
    hotList<<"你是不是啥"<<"楼上真傻";
    ui->hotComb->addItems(hotList);
    ui->hotComb->setEnabled(false);
}

void ToolPart::restartImage()
{
    ui->zoomIn->setEnabled(true);
    ui->zoomOut->setEnabled(true);
    ui->redPerLab->setText("50%");
    ui->greenPerLab->setText("50%");
    ui->bluePerLab->setText("50%");
    ui->zoomLab->setText("100%");
    ui->redSlider->setValue(ui->redSlider->maximum()/2);
    ui->greenSlider->setValue(ui->greenSlider->maximum()/2);
    ui->blueSlider->setValue(ui->blueSlider->maximum()/2);
    ui->frame->show();
}

void ToolPart::restartText()
{
    ui->hotComb->setEnabled(false);
    ui->verComb->setEnabled(false);
    ui->horiComb->setEnabled(false);
    ui->fontComboBox->setEnabled(false);
    ui->colorLab->setEnabled(false);
    ui->sizeSpin->setEnabled(false);
    ui->hotComb->setCurrentIndex(0);
    ui->verComb->setCurrentIndex(0);
    ui->horiComb->setCurrentIndex(0);
    ui->sizeSpin->setValue(16);
    ui->fontComboBox->setCurrentIndex(0);
    ui->frame_2->show();

}

void ToolPart::initSlider(QSlider *slider)
{
    slider->setRange(0,100);
    slider->setValue(50);

}

int ToolPart::transDirctWord(const QString &word)
{

    if(word=="顶部")
        return 1;
    if(word=="中间")
        return 2;
    if(word=="底部")
        return 3;

}

void ToolPart::on_turnGray_toggled(bool checked)
{

}

void ToolPart::on_compress_toggled(bool checked)
{
    qDebug()<<checked;
}

void ToolPart::on_autoMoveComb_toggled(bool checked)
{

}

void ToolPart::on_sizeSpin_valueChanged(int arg1)
{
    setFontSize(arg1);
}

void ToolPart::on_fontComboBox_currentFontChanged(const QFont &f)
{
    setFont(f);
}



void ToolPart::on_zoomIn_clicked()
{
    if (scale<8)
        scale=scale*2;
    ui->zoomLab->setText(QString::number(scale*100)+"%");
    emit zoomIn();
}

void ToolPart::on_zoomOut_clicked()
{
    if(scale>0.125)
        scale=scale/2;
    ui->zoomLab->setText(QString::number(scale*100)+"%");
    emit zoomOut();
}

void ToolPart::on_hotComb_currentIndexChanged(const QString &arg1)
{
    setEmojiString(arg1);
}



void ToolPart::on_verComb_currentIndexChanged(const QString &arg1)
{
    setPlaceId(this->transDirctWord(arg1),true);
}

void ToolPart::on_horiComb_currentIndexChanged(const QString &arg1)
{
    setPlaceId(this->transDirctWord(arg1),false);
}

void ToolPart::on_hotEdit_textChanged(const QString &arg1)
{
    setEmojiString(arg1);
}
