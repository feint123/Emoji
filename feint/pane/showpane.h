#ifndef SHOWPANE_H
#define SHOWPANE_H

#include <QWidget>

namespace Ui {
class ShowPane;
}

class ShowPane : public QWidget
{
    Q_OBJECT

public:
    explicit ShowPane(QWidget *parent = 0);
    ~ShowPane();

private:
    Ui::ShowPane *ui;
};

#endif // SHOWPANE_H
