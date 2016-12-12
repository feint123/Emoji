#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QWidget>

#include <widget/view/listview.h>

#include <net/invitationfactory.h>

namespace Ui {
class MainContent;
}

class MainContent : public QWidget
{
    Q_OBJECT

public:
    explicit MainContent(QWidget *parent = 0);
    ~MainContent();
    void refresh(QString tabName);
private:
    Ui::MainContent *ui;
    ListView* initCards();
    InvitationFactory *factory;
     QList<QVariant> cardList;
private slots:
    ListView* initCards(QList<QVariant>);
    void getTid(int id);

signals:
    void selectTid(int tid);
};

#endif // MAINCONTENT_H
