#ifndef MARKDOWNPLACE_H
#define MARKDOWNPLACE_H

#include "markdowntitle.h"

#include <QFrame>
#include <qfilesystemwatcher.h>

#include <pane/markdown/markdownedit.h>

#include <pane/menu/basemenu.h>

#include <widget/frame/transframe.h>


typedef QList<Image *> Images;
class MarkDownPlace:public QFrame,public BaseMenu
{
    Q_OBJECT

public:
    MarkDownPlace(QWidget *parent=0);


    // QWidget interface
    MarkDownEdit *getEdit() const;

    void setPadding(int value);

    void setNoteFile(QString noteFile);

    MarkDownTitle *getTitle() const;

public slots:
    void onEmitPreviewImages();
    void updateHighlighterLine();
    void onEmitOutNote();
    void onEmitOutImages();
protected:
    void resizeEvent(QResizeEvent *event);
signals:
    void resizeFrame();

    void previewImages(Images list);

    void outNoteAction(QString);
    void outImagesAction(QString);
private:
    MarkDownEdit *edit;
    MarkDownTitle *title;

    TransFrame *upFrame;
    TransFrame *downFrame;

    QFileSystemWatcher *watcher;

    int padding;
    QMenu *menu;
    QAction *insert_image;
    QAction *copyCont;
    QAction *cutCont;
    QAction *pasteCont;
    QAction *preImages;
    QAction *outCont;
    QAction *outImage;
    QAction *save;

    void createActions();
    void addShortCuts();
    void addActionToList();

    void resizeView();

    QRect lighterLine;


protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event);

};

#endif // MARKDOWNPLACE_H
