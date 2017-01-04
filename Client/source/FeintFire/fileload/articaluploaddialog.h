#ifndef ARTICALUPLOADDIALOG_H
#define ARTICALUPLOADDIALOG_H

#include <QDialog>
#include <QJsonDocument>

#include <pane/markdown/dialog/uploaddialog.h>

namespace Ui {
class ArticalUploadDialog;
}


class ArticalUploadDialog : public UploadDialog
{
    Q_OBJECT

public:
    explicit ArticalUploadDialog(QWidget *parent = 0);
    ~ArticalUploadDialog();

    QString getFilePath() const;
    void setFilePath(const QString &value);

    QStringList getTypeList() const;
    void setTypeList(const QStringList &value);
public slots:
    void onshared(bool,QString);

private slots:
    void on_quitBtn_clicked();

    void on_postBtn_clicked();

    void on_fileBtn_clicked();

    void on_upload_succcess(QJsonDocument doc);

private:
    QStringList typeList;
    Ui::ArticalUploadDialog *ui;
    void changeEvent(QEvent *e);
    QString filePath;



    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ARTICALUPLOADDIALOG_H
