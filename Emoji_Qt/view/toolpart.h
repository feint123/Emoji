#ifndef TOOLPART_H
#define TOOLPART_H

#include <QDialog>

namespace Ui {
class ToolPart;
}

class ToolPart : public QDialog
{
    Q_OBJECT

public:
    explicit ToolPart(QWidget *parent = 0);
    ~ToolPart();

private:
    Ui::ToolPart *ui;
};

#endif // TOOLPART_H
