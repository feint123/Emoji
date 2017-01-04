#ifndef MAINPART_H
#define MAINPART_H


#include "maincontent.h"

#include <QTabWidget>
#include <QWidget>

#include <widget/view/listview.h>

#include <util/graphic/feintsetting.h>

namespace Ui {
class MainPart;
}

class MainPart : public QWidget,public FeintSetting
{
    Q_OBJECT

public:
    explicit MainPart(QWidget *parent = 0);
    ~MainPart();
    void addTabs(QStringList tabs);
    bool flag=false;
private slots:
    void focusTab(int);
private:
    Ui::MainPart *ui;
    QTabWidget *tabWidget;
    QString baseStyle;

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // MAINPART_H
