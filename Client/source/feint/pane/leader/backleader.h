#ifndef BACKLEADER_H
#define BACKLEADER_H

#include <QWidget>

namespace Ui {
class BackLeader;
}

class BackLeader : public QWidget
{
    Q_OBJECT

public:
    explicit BackLeader(QWidget *parent = 0);

    /**设置返回按钮的类型**/
    void setBackId(int);
    ~BackLeader();

private slots:
    void on_pushButton_2_clicked();

signals:
    void back(int);

private:
    Ui::BackLeader *ui;
    int backId;
};

#endif // BACKLEADER_H
