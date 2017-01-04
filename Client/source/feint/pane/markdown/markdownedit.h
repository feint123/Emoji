#ifndef MARKDOWNEDIT_H
#define MARKDOWNEDIT_H

#include "markdownhighlighter.h"

#include <QMenu>
#include <QTextEdit>

#include <pane/markdown/html/markdowntohtml.h>

#include <pane/markdown/dialog/markdownimagedialog.h>

#include <widget/button/markdownimagebutton.h>

#include <widget/frame/imagepreview.h>



class MarkDownEdit:public QTextEdit
{
    Q_OBJECT

public:
    enum Theme{
        DAILY,
        DARK
    };

    explicit MarkDownEdit(QWidget *parent=0);

    void setTheme(Theme theme);
    MarkDownToHtml *getToHtml() const;
    void refreshFormat();
    QList<MarkdownImageButton *> getImageBtns() const;

    void setImageBtns(const QList<MarkdownImageButton *> &value);

    void clearContent();
    void setDefaultPath(const QString &value);

signals:

private slots:
    void on_insert_image();
    void on_insert_url();

    void on_create_image(QString alt,QString url,int w,int h);

    void on_insert_table();

    void showPreview(MarkdownImageButton *btn);

    void updateImgBtnLine();

    void hidePreview();
private:
    MarkDownHighlighter *lighter;
    void initDarkTheme();
    MarkDownToHtml *toHtml;
    ImagePreview *currentImage;

    void createActions();

    void insertImage(const QByteArray &url);

    void insertImage(const QImage &img);

    void insertImage(bool drag);

    void createImageDialog();

    QAction *insert_image;
    QAction *insert_url;
    QAction *insert_table;

    void translateLanguage();

    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

    QPoint pixDelta;

    MarkdownImageDialog *dialog;

    QList<MarkdownImageButton *> imageBtns;

    QList<ImagePreview *> previews;

    QString defaultPath;

    bool textChangedLock=false;
    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event);

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event);

    // QWidget interface
protected:
    void dropEvent(QDropEvent *event);
};

#endif // MARKDOWNEDIT_H
