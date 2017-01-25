#ifndef MARKDOWNQUICK_H
#define MARKDOWNQUICK_H

#include "markdownedit.h"
#include <QObject>


class MarkDownQuick:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int baseSize READ baseSize WRITE setBaseSize NOTIFY baseSizeChanged)

public:
    MarkDownQuick(MarkDownEdit *edit);

    int baseSize() const;

public slots:
    void addHeader1();
    void addHeader2();
    void addHeader3();
    void addHeader4();
    void addHeader5();
    void addHeader6();

    void addBlod();
    void addItalic();
    void addCode();

    void addOrderList();
    void addUnOrderList();
    void addBlock();

    void insertUrl();

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
    QAction *orderList;
    QAction *unOrderList;
    QAction *block;
    QAction *image;
    QAction *devide;
    QAction *zoomIn;
    QAction *zoomOut;

    QList<QAction*> actionList;

    void createActions();
    void addHeaders(int level);
    void zoom(bool in,int incre);
    void addShortCuts();
    void addDoubel(QString part);
    void addBlock(QString start);
    MarkDownEdit *edit;
    int m_baseSize;
};

#endif // MARKDOWNQUICK_H
