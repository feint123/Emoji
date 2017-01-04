#include "fbutton.h"
#include "fbuttonplugin.h"

#include <QtPlugin>

FButtonPlugin::FButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FButtonPlugin::createWidget(QWidget *parent)
{
    return new FButton(parent);
}

QString FButtonPlugin::name() const
{
    return QLatin1String("FButton");
}

QString FButtonPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FButtonPlugin::icon() const
{
    return QIcon();
}

QString FButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FButtonPlugin::isContainer() const
{
    return false;
}

QString FButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FButton\" name=\"fButton\">\n</widget>\n");
}

QString FButtonPlugin::includeFile() const
{
    return QLatin1String("fbutton.h");
}

