#ifndef LABELLABEL_H
#define LABELLABEL_H

#include <QLabel>
#include <QMouseEvent>



class LabelLabel:public QLabel
{
    Q_OBJECT
public:
    LabelLabel(QWidget* parent=0);
    LabelLabel(const QString & text);
    LabelLabel(const LabelLabel& label){
        this->text()=label.text();
    }

    ~LabelLabel();

    QString getRealText() const;
    void setRealText(const QString &value);

private:
    void mouseDoubleClickEvent(QMouseEvent* evnet);
     QString realText;

signals:
    void removeLabel(QString text);


};

#endif // LABELLABEL_H
