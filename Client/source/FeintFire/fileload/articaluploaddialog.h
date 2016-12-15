#ifndef ARTICALUPLOADDIALOG_H
#define ARTICALUPLOADDIALOG_H

#include <QDialog>

namespace Ui {
class ArticalUploadDialog;
}

class ArticalUploadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArticalUploadDialog(QWidget *parent = 0);
    ~ArticalUploadDialog();

    QString getFilePath() const;
    void setFilePath(const QString &value);

    QStringList getTypeList() const;
    void setTypeList(const QStringList &value);

private slots:
    void on_quitBtn_clicked();

    void on_postBtn_clicked();

    void on_fileBtn_clicked();

private:
    QStringList typeList;
    Ui::ArticalUploadDialog *ui;
    void changeEvent(QEvent *e);
    QString filePath;
};

#endif // ARTICALUPLOADDIALOG_H
