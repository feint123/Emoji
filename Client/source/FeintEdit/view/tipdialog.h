#ifndef TIPDIALOG_H
#define TIPDIALOG_H

#include <QDialog>


/**
 * @brief The TipDialog class
 * 展示提示信息
 */
class TipDialog:public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(int keep READ keep WRITE setKeep)
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize)
public:

    static TipDialog *getInstance(QWidget *parent=0);
    QString tip() const;
    ~TipDialog();
    int fontSize() const;

    int keep() const;

public slots:
    void setTip(QString tip);


    void showTip();

    void setFontSize(int fontSize);

    void hideTip();

    void setKeep(int keep);

private:
    TipDialog(QWidget *parent=0);
    static TipDialog *tipdialog;
    QString m_tip;

    int m_height;

    int m_fontSize;


    QTimer *timer;

    int m_keep;

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // TIPDIALOG_H
