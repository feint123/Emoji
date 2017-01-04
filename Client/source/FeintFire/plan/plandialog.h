#ifndef PLANDIALOG_H
#define PLANDIALOG_H

#include "plan.h"

#include <QDialog>

namespace Ui {
class PlanDialog;
}

class PlanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlanDialog(QWidget *parent = 0);
    static QStringList createLevel();
    static QHash<QString,QString> createType();
    ~PlanDialog();

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::PlanDialog *ui;

    void installFilter();
    int triPlace;
    int tri;

    Plan *plan;

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);



    // QWidget interface
    int getTriPlace() const;
    void setTriPlace(int value);

    int getTri() const;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PLANDIALOG_H
