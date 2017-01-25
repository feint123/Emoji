#ifndef IMAGEINFODIALOG_H
#define IMAGEINFODIALOG_H

#include <QDialog>

#include <pane/image/domain/image.h>

namespace Ui {
class ImageInfoDialog;
}

class ImageInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageInfoDialog(QWidget *parent = 0);
    ~ImageInfoDialog();
public slots:
    void setImage(Image *image);
private:
    Ui::ImageInfoDialog *ui;

    QString dealPath(QString path);
};

#endif // IMAGEINFODIALOG_H
