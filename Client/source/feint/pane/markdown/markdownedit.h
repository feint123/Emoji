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


typedef void (*HighLighter)(MarkDownHighlighter *lighter);
class MarkDownEdit:public QTextEdit,public BaseMenu
{
    Q_OBJECT
    Q_PROPERTY(QString noteFile READ noteFile WRITE setNoteFile)
    Q_PROPERTY(QString background READ background WRITE setBackground)
    Q_PROPERTY(QString color READ color WRITE setColor)
    Q_PROPERTY(QString scrollHandle READ scrollHandle WRITE setScrollHandle)
    Q_PROPERTY(QString scrollPage READ scrollPage WRITE setScrollPage)
public:
    enum Theme{
        DAILY,
        DARK
    };

    explicit MarkDownEdit(QWidget *parent=0);
    void setTheme();
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

    QString background() const
    {
        return m_background;
    }

    QString color() const
    {
        return m_color;
    }

    QString scrollHandle() const
    {
        return m_scrollHandle;
    }

    QString scrollPage() const
    {
        return m_scrollPage;
    }

    void setHigh(const HighLighter &value);

    void setQuickString(const QString &value);
public slots:
    void on_insert_image();

private slots:


    void on_insert_url();

    void on_create_image(QString alt,QString url,int w,int h);

    void showPreview(MarkdownImageButton *btn);

    void hidePreview();

public slots:
    void updateImgBtnLine();

    void setNoteFile(QString noteFile);

    void setBackground(QString background)
    {
        m_background = background;
    }

    void setColor(QString color)
    {
        m_color = color;
    }

    void setScrollHandle(QString scrollHandle)
    {
        m_scrollHandle = scrollHandle;
    }

    void setScrollPage(QString scrollPage)
    {
        m_scrollPage = scrollPage;
    }

private:

    QHash<QString,QImage> imageCache;
    MarkDownHighlighter *lighter;

    MarkDownToHtml *toHtml;
    ImagePreview *currentImage;

    QMenu *quickMenu;
    QString quickString;

    HighLighter high;

    MarkdownImageButton* createImageBtn(Image *image, int pX, int pY);
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

    QString m_background;

    QString m_color;

    QString m_scrollHandle;

    QString m_scrollPage;

protected:
    void dragEnterEvent(QDragEnterEvent *event);

    void wheelEvent(QWheelEvent *event);

    void dropEvent(QDropEvent *event);

    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MARKDOWNEDIT_H
