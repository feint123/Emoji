#ifndef NORMALTOOLPANE_H
#define NORMALTOOLPANE_H

#include <QDomDocument>
#include <QWidget>

namespace Ui {
class NormalToolPane;
}



class NormalToolPane : public QWidget
{
    Q_OBJECT

public:
    explicit NormalToolPane(QWidget *parent = 0);
    ~NormalToolPane();

private slots:
    void on_pushDownBtn_clicked();

    void on_pushUpBtn_clicked();

private:
    Ui::NormalToolPane *ui;
    void initTextColor();
    void initBackgroundColor();
    QDomDocument doc;
};

#endif // NORMALTOOLPANE_H
