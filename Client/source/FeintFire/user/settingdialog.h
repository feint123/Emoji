#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QJsonDocument>
#include <ftooglebutton.h>

#include <domain/app/setting.h>

#include <util/graphic/feintsetting.h>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog,public FeintSetting
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_styleTog_toggled(bool checked);

    void on_cacheTog_toggled(bool checked);

    void on_workTog_toggled(bool checked);

    void on_fButton_3_clicked();

private:
    Ui::SettingDialog *ui;
    void loadSetting();
    void createView(Setting *set);
    void setToggle(FToogleButton *tog,bool checked);
    QFile file;
    QJsonDocument doc;

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();

};

#endif // SETTINGDIALOG_H
