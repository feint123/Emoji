#ifndef MARKDOWNIMAGEDIALOG_H
#define MARKDOWNIMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class MarkdownImageDialog;
}

class MarkdownImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MarkdownImageDialog(QWidget *parent = 0);
    void setImageUrl(const QByteArray &url);
    void setImage(const QImage &img);
    void setIsDrag(bool drag);
    ~MarkdownImageDialog();

    void setDefaultPath(const QString &value);

private slots:
    void on_imageBtn_clicked();

    void on_widthLine_textChanged(const QString &arg1);

    void on_okBtn_clicked();

    void on_pushButton_clicked();

signals:
    void insertImage(QString alt,QString url,int w,int h);

private:
    Ui::MarkdownImageDialog *ui;
    int imgWidth;
    int imgHeight;
    void createDialog(QString filePath);
    void createDialog(const QImage &image);
    QImage img;
    QString defaultPath;
    bool drag=true;
};

#endif // MARKDOWNIMAGEDIALOG_H
