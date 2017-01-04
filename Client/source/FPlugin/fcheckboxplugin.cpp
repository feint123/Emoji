#include "fcheckbox.h"
#include "fcheckboxplugin.h"

#include <QtPlugin>

FCheckBoxPlugin::FCheckBoxPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FCheckBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FCheckBoxPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FCheckBoxPlugin::createWidget(QWidget *parent)
{
    return new FCheckBox(parent);
}

QString FCheckBoxPlugin::name() const
{
    return QLatin1String("FCheckBox");
}

QString FCheckBoxPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FCheckBoxPlugin::icon() const
{
    return QIcon();
}

QString FCheckBoxPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FCheckBoxPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FCheckBoxPlugin::isContainer() const
{
    return false;
}

QString FCheckBoxPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FCheckBox\" name=\"fCheckBox\">\n</widget>\n");
}

QString FCheckBoxPlugin::includeFile() const
{
    return QLatin1String("fcheckbox.h");
}

