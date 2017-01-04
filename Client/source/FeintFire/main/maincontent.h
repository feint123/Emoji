#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QWidget>

#include <widget/view/listview.h>

#include <net/invitationfactory.h>

#include <util/graphic/feintsetting.h>

namespace Ui {
class MainContent;
}

class MainContent : public QWidget,public FeintSetting
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
    QString baseStyle;
private slots:
    ListView* initCards(QList<QVariant>);
    void getTid(int id);

signals:
    void selectTid(int tid);

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // MAINCONTENT_H
