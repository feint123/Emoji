#ifndef MARKDOWNQUICK_H
#define MARKDOWNQUICK_H

#include <QObject>

#include <pane/markdown/markdownedit.h>


class MarkDownQuick:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int baseSize READ baseSize WRITE setBaseSize NOTIFY baseSizeChanged)

public:

    static MarkDownQuick *getInstance(MarkDownEdit *edit=0);
    ~MarkDownQuick();
    int baseSize() const;

    QList<QAction *> getActionList() const;

    void setEdit(MarkDownEdit *value);

    MarkDownEdit *getEdit() const;

public slots:
    void createActions();
    void addHeader1();
    void addHeader2();
    void addHeader3();
    void addHeader4();
    void addHeader5();
    void addHeader6();

    void addBlod();
    void addItalic();
    void addCode();
    void addDelete();

    void addOrderList();
    void addUnOrderList();
    void addBlock();

    void insertUrl();
    void insertImage();

    void zoomInEdit();
    void zoomOutEdit();

    void addDevide();
    void setBaseSize(int baseSize);

signals:
    void currentFontSize(int size);
    void baseSizeChanged(int baseSize);

private:
    QAction *header1;
    QAction *header2;
    QAction *header3;
    QAction *header4;
    QAction *header5;
    QAction *header6;
    QAction *bold;
    QAction *italic;
    QAction *code;
    QAction *del;
    QAction *orderList;
    QAction *unOrderList;
    QAction *block;
    QAction *image;
    QAction *devide;
    QAction *zoomIn;
    QAction *zoomOut;

    QList<QAction*> actionList;

    void addHeaders(int level);
    void zoom(bool in,int incre);
    void addShortCuts();
    void addDoubel(QString part);
    void addBlock(QString start);
    MarkDownEdit *edit;
    int m_baseSize;

    MarkDownQuick(MarkDownEdit *edit=0);

    static MarkDownQuick *quick;
};

#endif // MARKDOWNQUICK_H
