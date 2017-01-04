#ifndef PLANFRAME_H
#define PLANFRAME_H

#include "plan.h"
#include "plancard.h"
#include "plandialog.h"

#include <QGridLayout>
#include <QTimer>
#include <QWidget>
#include <qevent.h>

#include <util/json/jsondata.h>

#include <util/graphic/feintsetting.h>

namespace Ui {
class PlanFrame;
}

class PlanFrame : public QWidget,public FeintSetting
{
    Q_OBJECT
    Q_PROPERTY(int lineNum READ lineNum WRITE setLineNum NOTIFY lineNumChanged)
public:
    explicit PlanFrame(QWidget *parent = 0);
    void addCard();
    ~PlanFrame();

    int lineNum() const;

public slots:
    void setLineNum(int lineNum);
private slots:
    void addPlan(Plan* plan);
    void refreshItems();
    void on_fButton_clicked();

    void refresh();

    void deletePlanById(int id);


signals:
    void lineNumChanged(int lineNum);
private:
    Ui::PlanFrame *ui;

    QGridLayout *grid;
    QVBoxLayout *vb;
    PlanDialog *planDialog;

    JsonData *data;

    int m_lineNum;

    QTimer *timer;
    QString planPath;
    QList<PlanCard*> cardList;

    void initLayout();
    QList<Plan*> loadDate(QString path);
    void resizeEvent(QResizeEvent *event);
    void createCardList(QList<Plan *> planList);


    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // PLANFRAME_H
