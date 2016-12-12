#ifndef CARDCELL_H
#define CARDCELL_H

#include <QWidget>

#include <domain/articalcard.h>

#include <widget/fscaleframe.h>

namespace Ui {
class CardCell;
}

class CardCell : public FScaleFrame
{
    Q_OBJECT

public:
    explicit CardCell(QWidget *parent = 0);
    ~CardCell();
    void setCard(ArticalCard card);

private:
    Ui::CardCell *ui;
};

#endif // CARDCELL_H
