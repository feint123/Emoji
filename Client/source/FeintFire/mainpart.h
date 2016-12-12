#ifndef MAINPART_H
#define MAINPART_H


#include <QTabWidget>
#include <QWidget>

#include <widget/view/listview.h>

namespace Ui {
class MainPart;
}

class MainPart : public QWidget
{
    Q_OBJECT

public:
    explicit MainPart(QWidget *parent = 0);
    ~MainPart();
    void addTabs(QStringList tabs);
private slots:
    void focusTab(int);
private:
    Ui::MainPart *ui;
    QTabWidget *tabWidget;

};

#endif // MAINPART_H
