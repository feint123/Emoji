#ifndef NORMALTOOLPANE_H
#define NORMALTOOLPANE_H

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

private:
    Ui::NormalToolPane *ui;
};

#endif // NORMALTOOLPANE_H
