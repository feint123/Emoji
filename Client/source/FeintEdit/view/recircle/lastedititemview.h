#ifndef LASTEDITITEMVIEW_H
#define LASTEDITITEMVIEW_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <qtextedit.h>

#include <domain/lastedit.h>



class LastEditItemView:public QFrame
{
    Q_OBJECT
public:
    LastEditItemView(QWidget *parent=0);

    void setLastEdit(LastEdit *edit);

private slots:
    void removeLastEdit();
    void openNote();
private:
    QLabel *title;
    QTextEdit *content;
    QLabel *data;
    QPushButton *remove;
    QPushButton *open;
    QString file;
    QString bookFile;
    int id;

    void createView();
    bool hasNote;
    bool checkhasNote(QString file,QString bookFile);

    QPushButton *createBtn(QString text);

    QLabel *createLabel(QString text="");

    QImage img;
    QImage deleteImage;

protected:
    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);


};

#endif // LASTEDITITEMVIEW_H
