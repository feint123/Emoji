#ifndef DIALOGSHOWUTIL_H
#define DIALOGSHOWUTIL_H

#include <QWidget>



class DialogShowUtil
{
public:
    DialogShowUtil();

    static void show(QWidget *parent,QWidget *dialog,int offset=0);
};

#endif // DIALOGSHOWUTIL_H
