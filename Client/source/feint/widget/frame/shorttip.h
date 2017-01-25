#ifndef SHORTTIP_H
#define SHORTTIP_H

#include <QFrame>
#include <QLabel>



class ShortTip:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString tipStr READ tipStr WRITE setTipStr NOTIFY tipStrChanged)
public:
    static ShortTip* getInstance(QWidget *parent);

    ~ShortTip();
    QString tipStr() const;

    void showTip(int mesc);

public slots:
    void setTipStr(QString tipStr);

signals:
    void tipStrChanged(QString tipStr);

private:
    static ShortTip* tip;
    ShortTip(QWidget *parent);
    QLabel *tipLab;
    // QWidget interface
    QString m_tipStr;

    QTimer *timer;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SHORTTIP_H
