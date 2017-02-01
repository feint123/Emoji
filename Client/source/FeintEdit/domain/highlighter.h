#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <qobject.h>



class Highlighter:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString header READ header WRITE setHeader)
    Q_PROPERTY(QString bold READ bold WRITE setBold)
    Q_PROPERTY(QString italic READ italic WRITE setItalic)
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString del READ del WRITE setDel)
    Q_PROPERTY(QString devide READ devide WRITE setDevide)
    Q_PROPERTY(QString orderList READ orderList WRITE setOrderList)
    Q_PROPERTY(QString unOrderList READ unOrderList WRITE setUnOrderList)
    Q_PROPERTY(QString block READ block WRITE setBlock)
    Q_PROPERTY(QString img READ img WRITE setImg)

public:
    Highlighter();
    QString header() const
    {
        return m_header;
    }

    QString bold() const
    {
        return m_bold;
    }

    QString italic() const
    {
        return m_italic;
    }

    QString code() const
    {
        return m_code;
    }

    QString del() const
    {
        return m_del;
    }

    QString devide() const
    {
        return m_devide;
    }

    QString orderList() const
    {
        return m_orderList;
    }

    QString unOrderList() const
    {
        return m_unOrderList;
    }

    QString block() const
    {
        return m_block;
    }

    QString img() const
    {
        return m_img;
    }

public slots:
    void setHeader(QString header)
    {
        m_header = header;
    }

    void setBold(QString bold)
    {
        m_bold = bold;
    }

    void setItalic(QString italic)
    {
        m_italic = italic;
    }

    void setCode(QString code)
    {
        m_code = code;
    }

    void setDel(QString del)
    {
        m_del = del;
    }

    void setDevide(QString devide)
    {
        m_devide = devide;
    }

    void setOrderList(QString orderList)
    {
        m_orderList = orderList;
    }

    void setUnOrderList(QString unOrderList)
    {
        m_unOrderList = unOrderList;
    }

    void setBlock(QString block)
    {
        m_block = block;
    }

    void setImg(QString img)
    {
        m_img = img;
    }

private:
    QString m_header;
    QString m_bold;
    QString m_italic;
    QString m_code;
    QString m_del;
    QString m_devide;
    QString m_orderList;
    QString m_unOrderList;
    QString m_block;
    QString m_img;
};

#endif // HIGHLIGHTER_H
