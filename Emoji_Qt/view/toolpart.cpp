#include "toolpart.h"
#include "ui_toolpart.h"

ToolPart::ToolPart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolPart)
{
    ui->setupUi(this);
}

ToolPart::~ToolPart()
{
    delete ui;
}
