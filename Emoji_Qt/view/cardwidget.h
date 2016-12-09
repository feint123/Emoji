#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QDate>
#include <QWidget>

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(QWidget *parent = 0);
    void createCard(QString title,QString tip,QDate date,float hot);
    ~CardWidget();

private:
    Ui::CardWidget *ui;
};

#endif // CARDWIDGET_H
