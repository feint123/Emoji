#ifndef ARTICALAREA_H
#define ARTICALAREA_H

#include <QWidget>

namespace Ui {
class ArticalArea;
}

class ArticalArea : public QWidget
{
    Q_OBJECT

public:
    explicit ArticalArea(QWidget *parent = 0);
    ~ArticalArea();

public slots:
    void load(int articalId);

private:
    Ui::ArticalArea *ui;
};

#endif // ARTICALAREA_H
