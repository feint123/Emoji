#ifndef RECIRCLEITEMVIEW_H
#define RECIRCLEITEMVIEW_H

#include <QLabel>
#include <fbutton.h>
#include <qframe.h>

#include <domain/recirclepage.h>



class RecircleItemView:public QFrame
{
    Q_OBJECT
public:
    RecircleItemView(QWidget *parent=0);
    void setPage(RecirclePage *page);

public slots:
    void restorePage();
    void deletePage();

private:
    QImage img;
    QString title;
    QString file;
    QString bookfile;
    int type;
    QLabel *lab;
    QPushButton *restore;
    QPushButton *del;
    QPushButton *preview;

    QPushButton* createBtn(QString text);

    void restoreNote();
    void restoreBook();

    void deleteNote(QString filename, QString after);
    void deleteBook();

    void deleteFrameRecircle(QString filename);

    void wrongTip(QString tip);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

    void enterEvent(QEvent *event);

    void leaveEvent(QEvent *event);
};

#endif // RECIRCLEITEMVIEW_H
