#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <ftooglebutton.h>

#include <view/tipdialog.h>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_fToogleButton_toggled(bool checked);

    void on_submitBtn_clicked();

    void on_defaultPathBtn_clicked();

private:
    Ui::SettingDialog *ui;
    TipDialog *tip;
    TipDialog* createTip();
    void createView();
    void setToggled(FToogleButton *tog,bool checked);
};

#endif // SETTINGDIALOG_H
