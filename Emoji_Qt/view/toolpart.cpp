#include "toolpart.h"
#include "ui_toolpart.h"
#include <QDebug>

ToolPart::ToolPart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolPart)
{
    ui->setupUi(this);
    initImage();

}

void ToolPart::startZoom()
{
    ui->zoomIn->setEnabled(true);
    ui->zoomOut->setEnabled(true);
}

ToolPart::~ToolPart()
{
    delete ui;
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
}

void ToolPart::initSlider(QSlider *slider)
{
    slider->setRange(0,100);
    slider->setValue(50);

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
