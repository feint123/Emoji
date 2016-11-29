#include "filepart.h"
#include "ui_filepart.h"

FilePart::FilePart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilePart)
{
    ui->setupUi(this);
}

FilePart::~FilePart()
{
    delete ui;
}
