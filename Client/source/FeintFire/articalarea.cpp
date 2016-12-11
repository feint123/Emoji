#include "articalarea.h"
#include "ui_articalarea.h"

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

}
