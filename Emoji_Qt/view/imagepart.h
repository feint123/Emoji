#ifndef IMAGEPART_H
#define IMAGEPART_H

#include <QDialog>

namespace Ui {
class ImagePart;
}

class ImagePart : public QDialog
{
    Q_OBJECT

public:
    explicit ImagePart(QWidget *parent = 0);
    ~ImagePart();

private:
    Ui::ImagePart *ui;
};

#endif // IMAGEPART_H
