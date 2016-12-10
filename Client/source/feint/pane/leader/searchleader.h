#ifndef SEARCHLEADER_H
#define SEARCHLEADER_H

#include <QWidget>

namespace Ui {
class SearchLeader;
}

class SearchLeader : public QWidget
{
    Q_OBJECT

public:
    explicit SearchLeader(QWidget *parent = 0);
    ~SearchLeader();

signals:
    void showMenu(bool);

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchLeader *ui;
    bool isMenuShow;
};

#endif // SEARCHLEADER_H
