#ifndef TOOLPAINT_H
#define TOOLPAINT_H

#include <QWidget>

namespace Ui {
class ToolPaint;
}

class Q_DECL_EXPORT ToolPaint : public QWidget
{
    Q_OBJECT

public:
    explicit ToolPaint(QWidget *parent = 0);
    ~ToolPaint();

private:
    Ui::ToolPaint *ui;
};

#endif // TOOLPAINT_H
