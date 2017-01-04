#include "setting.h"

Setting::Setting()
{

}

QString Setting::font_family() const
{
    return m_font_family;
}

QString Setting::style() const
{
    return m_style;
}

QString Setting::cache_area() const
{
    return m_cache_area;
}

QString Setting::workspacing() const
{
    return m_workspacing;
}

int Setting::font_size() const
{
    return m_font_size;
}

int Setting::cacheable() const
{
    return m_cacheable;
}

int Setting::defaultable() const
{
    return m_defaultable;
}

int Setting::auto_style() const
{
    return m_auto_style;
}

void Setting::setFont_family(QString font_family)
{
    m_font_family = font_family;
}

void Setting::setStyle(QString style)
{
    m_style = style;
}

void Setting::setCache_area(QString cache_area)
{
    m_cache_area = cache_area;
}

void Setting::setWorkspacing(QString workspacing)
{
    m_workspacing = workspacing;
}

void Setting::setFont_size(int font_size)
{
    m_font_size = font_size;
}

void Setting::setCacheable(int cacheable)
{
    m_cacheable = cacheable;
}

void Setting::setDefaultable(int defaultable)
{
    m_defaultable = defaultable;
}

void Setting::setAuto_style(int auto_style)
{
    m_auto_style = auto_style;
}

