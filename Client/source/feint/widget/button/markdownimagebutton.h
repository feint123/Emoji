#ifndef MARKDOWNIMAGEBUTTON_H
#define MARKDOWNIMAGEBUTTON_H

#include <QAction>
#include <QMenu>
#include <fbutton.h>

#include <pane/image/domain/image.h>



class MarkdownImageButton:public FButton
{
    Q_OBJECT

public:
    MarkdownImageButton(QWidget *parent=0);

    void createView();

    void updatePosition(QRect rect);

    void setImage(Image *value);

    Image *getImage() const;

    QString getDefaultPath() const;
    void setDefaultPath(const QString &value);

    QString getNoteFile() const;
    void setNoteFile(const QString &value);

signals:
    void previewImage(MarkdownImageButton *btn);
    void updateImageInfo(QWidget *parent,Image *img,QString);
    void hideImage();

public slots:

    void onEmitUpdateImgInfo();

private:

    bool dragAction=false;

    QPoint oldPoint;

    QMenu *menu;
    QAction *copyImage;
    QAction *cutImage;
    QAction *outImage;
    QAction *updateImage;
    void createAction();
    void addShortCuts();
    QString defaultPath;
    QString noteFile;

    Image *image;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);

    void contextMenuEvent(QContextMenuEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // MARKDOWNIMAGEBUTTON_H
