#include "fcircle.h"
#include "fcircleplugin.h"

#include <QtPlugin>

FCirclePlugin::FCirclePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FCirclePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FCirclePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FCirclePlugin::createWidget(QWidget *parent)
{
    return new FCircle(parent);
}

QString FCirclePlugin::name() const
{
    return QLatin1String("FCircle");
}

QString FCirclePlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FCirclePlugin::icon() const
{
    return QIcon();
}

QString FCirclePlugin::toolTip() const
{
    return QLatin1String("");
}

QString FCirclePlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FCirclePlugin::isContainer() const
{
    return false;
}

QString FCirclePlugin::domXml() const
{
    return QLatin1String("<widget class=\"FCircle\" name=\"fCircle\">\n</widget>\n");
}

QString FCirclePlugin::includeFile() const
{
    return QLatin1String("fcircle.h");
}

