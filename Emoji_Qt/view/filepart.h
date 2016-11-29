#ifndef FILEPART_H
#define FILEPART_H

#include <QDialog>

namespace Ui {
class FilePart;
}

class FilePart : public QDialog
{
    Q_OBJECT

public:
    explicit FilePart(QWidget *parent = 0);
    ~FilePart();

private:
    Ui::FilePart *ui;
};

#endif // FILEPART_H
