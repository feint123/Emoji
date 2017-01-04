#ifndef BACKLEADER_H
#define BACKLEADER_H

#include <QWidget>

#include <util/graphic/feintsetting.h>

namespace Ui {
class BackLeader;
}

class BackLeader : public QWidget,public FeintSetting
{
    Q_OBJECT

public:
    explicit BackLeader(QWidget *parent = 0);

    bool flag;
    /**设置返回按钮的类型**/
    void setBackId(int);
    void setIcon(QIcon back,QIcon setting);
    void setTitle(QString);
    QString getTitle();
    ~BackLeader();

private slots:

    void on_backBtn_clicked();

signals:
    void back(int);

private:
    Ui::BackLeader *ui;
    int backId;
    QString title;
    QString baseStyle;

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // BACKLEADER_H
