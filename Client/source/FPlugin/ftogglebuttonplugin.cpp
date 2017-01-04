#include "ftogglebutton.h"
#include "ftogglebuttonplugin.h"

#include <QtPlugin>

FToggleButtonPlugin::FToggleButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FToggleButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FToggleButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FToggleButtonPlugin::createWidget(QWidget *parent)
{
    return new FToggleButton(parent);
}

QString FToggleButtonPlugin::name() const
{
    return QLatin1String("FToggleButton");
}

QString FToggleButtonPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FToggleButtonPlugin::icon() const
{
    return QIcon();
}

QString FToggleButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FToggleButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FToggleButtonPlugin::isContainer() const
{
    return false;
}

QString FToggleButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FToggleButton\" name=\"fToggleButton\">\n</widget>\n");
}

QString FToggleButtonPlugin::includeFile() const
{
    return QLatin1String("ftogglebutton.h");
}

