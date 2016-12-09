#ifndef CARDSHOW_H
#define CARDSHOW_H

#include <QWidget>

#include <domain/card.h>

namespace Ui {
class CardShow;
}

class CardShow : public QWidget
{
    Q_OBJECT

public:
    explicit CardShow(QWidget *parent = 0);
    CardShow(Card card);
    ~CardShow();

private:
    Ui::CardShow *ui;
};

#endif // CARDSHOW_H
