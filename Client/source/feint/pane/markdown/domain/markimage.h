#ifndef MARKIMAGE_H
#define MARKIMAGE_H

#include <QObject>



class MarkImage:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(QString path READ path WRITE setPath)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
    Q_PROPERTY(int posX READ posX WRITE setPosX)
    Q_PROPERTY(int posY READ posY WRITE setPosY)
    Q_PROPERTY(int anchor READ anchor WRITE setAnchor)
    Q_PROPERTY(QString mark READ mark WRITE setMark)
public:
    MarkImage();
    int id() const;

    QString tip() const;

    QString path() const;

    int width() const;

    int height() const;

    int posX() const;

    int posY() const;

    int anchor() const;

    QString mark() const;

public slots:
    void setId(int id);

    void setTip(QString tip);

    void setPath(QString path);

    void setWidth(int width);

    void setHeight(int height);

    void setPosX(int posX);

    void setPosY(int posY);

    void setAnchor(int anchor);

    void setMark(QString mark);

private:
    int m_id;
    QString m_tip;
    QString m_path;
    int m_width;
    int m_height;
    int m_posX;
    int m_posY;
    int m_anchor;
    QString m_mark;
};

#endif // MARKIMAGE_H
