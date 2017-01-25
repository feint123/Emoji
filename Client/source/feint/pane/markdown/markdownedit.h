#ifndef MARKDOWNEDIT_H
#define MARKDOWNEDIT_H

#include "markdownhighlighter.h"

#include <QMenu>
#include <QTextEdit>

#include <pane/markdown/html/markdowntohtml.h>

#include <pane/markdown/dialog/markdownimagedialog.h>

#include <widget/button/markdownimagebutton.h>

#include <widget/frame/imagepreview.h>

#include <pane/menu/basemenu.h>



class MarkDownEdit:public QTextEdit,public BaseMenu
{
    Q_OBJECT
    Q_PROPERTY(QString noteFile READ noteFile WRITE setNoteFile)
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
    void clearContent();
    void setDefaultPath(const QString &value);
    MarkDownHighlighter *getLighter() const;

    QList<Image *> getImageList();

    QString noteFile() const;

    QMenu *getQuickMenu() const;

    void setQuickMenu(QMenu *value);

private slots:
    void on_insert_image();

    void on_insert_url();

    void on_create_image(QString alt,QString url,int w,int h);

    void showPreview(MarkdownImageButton *btn);

    void hidePreview();

public slots:
    void updateImgBtnLine();

    void setNoteFile(QString noteFile);

private:

    QHash<QString,QImage> imageCache;
    MarkDownHighlighter *lighter;

    void initDarkTheme();
    MarkDownToHtml *toHtml;
    ImagePreview *currentImage;

    QMenu *quickMenu;

    MarkdownImageButton* createImageBtn(QString alt,QString path,int w,int h,int pX,int pY);
    MarkdownImageButton* createImageBtn(int id, int px, int py);

    void clearImageBtns();


    void insertImage(const QByteArray &url);

    void insertImage(const QImage &img);

    void insertImage(bool drag);

    void createImageDialog();

    void keyPressEvent(QKeyEvent *event);


    QPoint pixDelta;

    MarkdownImageDialog *dialog;

    QList<MarkdownImageButton *> imageBtns;

    QString defaultPath;

    FileUtil *fileUtil;

    bool textChangedLock=false;



    QString m_noteFile;

protected:
    void dragEnterEvent(QDragEnterEvent *event);

    void wheelEvent(QWheelEvent *event);

    void dropEvent(QDropEvent *event);

    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MARKDOWNEDIT_H
