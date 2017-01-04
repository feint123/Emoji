#include "uploaddialog.h"

UploadDialog::UploadDialog(QWidget *parent):
    QDialog(parent)
{

}

int UploadDialog::getDelay() const
{
    return delay;
}

void UploadDialog::setDelay(int value)
{
    delay = value;
}
