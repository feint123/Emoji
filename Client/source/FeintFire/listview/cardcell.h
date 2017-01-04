#ifndef CARDCELL_H
#define CARDCELL_H

#include <QWidget>




#include <widget/frame/fscaleframe.h>

#include <domain/response/invitationcard.h>

#include <util/graphic/feintsetting.h>



namespace Ui {
class CardCell;
}

class CardCell : public FScaleFrame,public FeintSetting
{
    Q_OBJECT

public:
    explicit CardCell(QWidget *parent = 0);
    ~CardCell();
 //   void setCard(ArticalCard card);
    void setCard(InvitationCard card);

private:
    Ui::CardCell *ui;
    QString baseStyle;
    QString titleStyle;

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // CARDCELL_H
