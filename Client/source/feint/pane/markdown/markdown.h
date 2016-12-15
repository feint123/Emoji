#ifndef MARKDOWN_H
#define MARKDOWN_H

#include "markdownedit.h"

#include <QWidget>

namespace Ui {
class markdown;
}

class MarkDown : public QWidget
{
    Q_OBJECT

public:
    explicit MarkDown(QWidget *parent = 0);
    ~MarkDown();

private slots:
    void on_fileBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::markdown *ui;
    MarkDownEdit *markdown;
};

#endif // MARKDOWN_H
