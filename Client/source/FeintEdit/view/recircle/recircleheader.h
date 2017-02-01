#ifndef RECIRCLEHEADER_H
#define RECIRCLEHEADER_H

#include <QDialog>
#include <qframe.h>

#include <view/abstracttabbar.h>


class RecircleHeader : public AbstractTabBar
{
    Q_OBJECT
    Q_PROPERTY(int underLineHeight READ underLineHeight WRITE setUnderLineHeight)
    Q_PROPERTY(QRect underLine READ underLine WRITE setUnderLine NOTIFY underLineChanged)
public:
    explicit RecircleHeader(QWidget *parent = 0);
    ~RecircleHeader();

    int underLineHeight() const;

    QRect underLine() const;

    void addItem(QString text="");


public slots:
    void setUnderLineHeight(int underLineHeight);

    void setUnderLine(QRect underLine);

signals:
    void underLineChanged(QRect underLine);

private:
    // QWidget interface
    int m_underLineHeight;

    QRect m_underLine;

protected:
    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);

protected:
    QPropertyAnimation *createAnim();
    void startAnim(QPropertyAnimation *anim);
};

#endif // RECIRCLEHEADER_H
