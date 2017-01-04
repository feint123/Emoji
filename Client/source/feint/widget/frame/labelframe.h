#ifndef LABELFRAME_H
#define LABELFRAME_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>



class LabelFrame:public QFrame
{
    Q_OBJECT
public:
    LabelFrame(QWidget* parent);
    QString getLabelString() const;

private slots:
    void wantSplite(QString string);
    void deletePartOfLableString(QString str);
private:
    QList<QLabel> labelList;
    QLineEdit *edit;
    QHBoxLayout *hb;
    void addLabel();
    QString labelString;

};

#endif // LABELFRAME_H
