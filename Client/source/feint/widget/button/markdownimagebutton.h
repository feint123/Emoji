#ifndef MARKDOWNIMAGEBUTTON_H
#define MARKDOWNIMAGEBUTTON_H

#include <fbutton.h>



class MarkdownImageButton:public FButton
{
    Q_OBJECT
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath)
    Q_PROPERTY(QString imageTip READ imageTip WRITE setImageTip)
    Q_PROPERTY(int imageWidth READ imageWidth WRITE setImageWidth)
    Q_PROPERTY(int imageHeight READ imageHeight WRITE setImageHeight)
    Q_PROPERTY(QString posMark READ posMark WRITE setPosMark)
    Q_PROPERTY(int  anchor READ anchor WRITE setAnchor)
public:
    MarkdownImageButton(QWidget *parent=0);

    QString imagePath() const;
    QString imageTip() const;

    int imageWidth() const;

    int imageHeight() const;

    void createView();

    void updatePosition(QRect rect);


    int lineHeight() const;

    QString posMark() const;

    int anchor() const;

signals:
    void previewImage(MarkdownImageButton *btn);

    void hideImage();

public slots:
    void setImagePath(QString imagePath);
    void setImageTip(QString imageTip);

    void setImageWidth(int imageWidth);

    void setImageHeight(int imageHeight);


    void setPosMark(QString posMark);

    void setAnchor(int anchor);

private:
    QString m_imagePath;
    QString m_imageTip;
    int m_imageWidth;
    int m_imageHeight;

    bool dragAction=false;

    QPoint oldPoint;

    QString m_posMark;

    int m_anchor;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);

};

#endif // MARKDOWNIMAGEBUTTON_H
