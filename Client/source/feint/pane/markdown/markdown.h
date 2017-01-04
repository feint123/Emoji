#ifndef MARKDOWN_H
#define MARKDOWN_H

#include "markdownedit.h"
#include "markdownmanager.h"

#include <QTimer>
#include <QWidget>

#include <pane/markdown/dialog/uploaddialog.h>

#include <util/graphic/feintsetting.h>

namespace Ui {
class markdown;
}

class MarkDown : public QWidget,public FeintSetting
{
    Q_OBJECT

public:
    explicit MarkDown(QWidget *parent = 0,UploadDialog *uploadWidget=0,int miniWidth=0);
    ~MarkDown();

    QString getTitle() ;
    void setTitle(const QString &value);


    void setUploadWidget(UploadDialog *value);

    void createControlIcon(QStringList icons);

    QString getCachePath() const;
    void setCachePath(const QString &value);

    void createFormat();

private slots:
    void on_fileBtn_clicked();

    void on_saveBtn_clicked();

    void on_shareBtn_clicked();

    void on_text_changed();

    QString saveFile();

    void on_newBtn_clicked();

    void on_saveOtherBtn_clicked();

    void on_save_cache();


signals:
    void startSharing(bool,QString);
    void titleChanged(QString);
    void reSize(QSize size,bool isFull);


private:
    Ui::markdown *ui;
    MarkDownEdit *markdown;
    QTextEdit *preview;
    MarkdownManager *manager;
    QString title;
    QString fileDefaultPath;
    QString cutTitle(const QString& title);

    void createActions();
    void loadCache();

    bool saved;
    QSize size;

    QTimer *timer;

    UploadDialog *uploadWidget;

    QString cachePath;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

    // FeintSetting interface
public:
    void createDailyStyle();
    void createDarkStyle();
};

#endif // MARKDOWN_H
