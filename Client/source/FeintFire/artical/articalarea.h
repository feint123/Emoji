#ifndef ARTICALAREA_H
#define ARTICALAREA_H

#include <QWidget>

#include <domain/response/artical.h>



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
    void loadArtical(Artical*);
private:
    Ui::ArticalArea *ui;
};

#endif // ARTICALAREA_H
