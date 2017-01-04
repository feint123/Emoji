#ifndef SETTING_H
#define SETTING_H

#include <QObject>



class Setting:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString font_family READ font_family WRITE setFont_family)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString cache_area READ cache_area WRITE setCache_area)
    Q_PROPERTY(QString workspacing READ workspacing WRITE setWorkspacing)
    Q_PROPERTY(int font_size READ font_size WRITE setFont_size)
    Q_PROPERTY(int cacheable READ cacheable WRITE setCacheable)
    Q_PROPERTY(int defaultable READ defaultable WRITE setDefaultable)
    Q_PROPERTY(int auto_style READ auto_style WRITE setAuto_style)
private:
    QString m_font_family;

    QString m_style;

    QString m_cache_area;

    QString m_workspacing;

    int m_font_size;

    int m_cacheable;

    int m_defaultable;

    int m_auto_style;

public:
    Setting();
    QString font_family() const;
    QString style() const;

    QString cache_area() const;

    QString workspacing() const;

    int font_size() const;

    int cacheable() const;

    int defaultable() const;

    int auto_style() const;

public slots:
    void setFont_family(QString font_family);
    void setStyle(QString style);
    void setCache_area(QString cache_area);
    void setWorkspacing(QString workspacing);
    void setFont_size(int font_size);
    void setCacheable(int cacheable);
    void setDefaultable(int defaultable);
    void setAuto_style(int auto_style);
};

#endif // SETTING_H
