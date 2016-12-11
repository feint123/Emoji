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
private slots:
    ListView* initCards(QList<QVariant>);
};

#endif // MAINCONTENT_H
