#ifndef UPLOADARTICAL_H
#define UPLOADARTICAL_H

#include <QObject>
#include <fobject.h>



class UploadArtical:public FObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString tip READ tip WRITE setTip)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString label READ label WRITE setLabel)
public:
    UploadArtical();

    QString content() const;

    QString title() const;

    QString tip() const;

    QString type() const;

    QString label() const;



public slots:
    void setContent(QString content);

    void setTitle(QString title);

    void setTip(QString tip);

    void setType(QString type);

    void setLabel(QString label);

private:

    QString m_content;
    QString m_title;
    QString m_tip;
    QString m_type;
    QString m_label;
};

#endif // UPLOADARTICAL_H
