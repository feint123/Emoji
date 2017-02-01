#ifndef RECIRCLE_H
#define RECIRCLE_H

#include "recircleheader.h"

#include <QFrame>

#include <widget/view/listview.h>

#include <domain/recirclepage.h>

#include <domain/appmessage.h>

class Recircle:public QFrame
{
    Q_OBJECT
public:
    Recircle(QWidget *parent);

    void setImg(const QImage &value);


    void setFirstShow(bool value);

public slots:
    void refreshList();

    void updateRecircleIndex(int i);

private slots:
    void animBack();
private:
    QRect start;
    QRect end;
    QImage img;
    ListView *list;
    RecircleHeader *header;
    AppMessage::TYPE type;
    void createHeader();
    void updateListData();
    void updateListData(AppMessage::TYPE type);
    bool firstShow=true;
    void listDataChangeAnimation();

    int headerH;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);
};

#endif // RECIRCLE_H
