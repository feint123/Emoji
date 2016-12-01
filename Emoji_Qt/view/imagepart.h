#ifndef IMAGEPART_H
#define IMAGEPART_H

#include <QDialog>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class ImagePart;
}

class ImagePart : public QDialog
{
    Q_OBJECT

public:
    explicit ImagePart(QWidget *parent = 0);
    ~ImagePart();
    bool loadFile();
    QString getImagePath() const;
    void setImagePath(const QString &value);

public slots:
    void changeTextSize(int size);
    void changeTextFont(const QFont &font);
    void zoomIn();
    void zoomOut();
    void scaleImage(double factor);
private:
    Ui::ImagePart *ui;
    QLabel *label;
    QString imagePath;
    QImage image;
    QScrollArea *scrollArea;
    void setImage(const QImage &image);

    double scaleFactor;
};

#endif // IMAGEPART_H
