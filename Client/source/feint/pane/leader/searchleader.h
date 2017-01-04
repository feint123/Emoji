#ifndef SEARCHLEADER_H
#define SEARCHLEADER_H

#include <QWidget>

#include <util/graphic/feintsetting.h>

namespace Ui {
class SearchLeader;
}

class SearchLeader : public QWidget,public FeintSetting
{
    Q_OBJECT

public:
    explicit SearchLeader(QWidget *parent = 0);
    void setMenuIcon(QIcon icon);

    ~SearchLeader();
    bool flag=false;
    bool getIsMenuShow() const;
    void setIsMenuShow(bool value);

signals:
    void showMenu(bool);

private slots:

    void on_menuBtn_clicked();

private:
    Ui::SearchLeader *ui;
    bool isMenuShow;

    QString baseStyle;

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // SEARCHLEADER_H
