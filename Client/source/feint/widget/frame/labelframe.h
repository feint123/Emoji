#ifndef LABELFRAME_H
#define LABELFRAME_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>



class LabelFrame:public QFrame
{
    Q_OBJECT
public:
    LabelFrame(QWidget* parent);
private:
    QList<QLabel> labelList;
    QLineEdit *edit;
};

#endif // LABELFRAME_H
