#ifndef CONTROLFLOATBUTTON_H
#define CONTROLFLOATBUTTON_H

#include <QFrame>
#include <fbutton.h>



class ControlFloatButton:public QFrame
{
    Q_OBJECT

public:
    ControlFloatButton(QWidget *parent=0);
    void addBtn(const QIcon &icon);
    void addBtn(const QIcon &icon,QString tip);
    void setIcon(const QIcon &showed,const QIcon &hide);
private:
    QList<FButton *> btnList;
    FButton * controlBtn;
    bool showed=true;
    QIcon showedIcon;
    QIcon hideIcon;

    FButton * createBasicButton();
    // QWidget interface
private slots:
    void onControlClicked();

public slots:
    void restore();

signals:
    void controlClicked(int);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // CONTROLFLOATBUTTON_H
