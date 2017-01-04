#include "fradiobutton.h"
#include "fradiobuttonplugin.h"

#include <QtPlugin>

FRadioButtonPlugin::FRadioButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FRadioButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FRadioButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FRadioButtonPlugin::createWidget(QWidget *parent)
{
    return new FRadioButton(parent);
}

QString FRadioButtonPlugin::name() const
{
    return QLatin1String("FRadioButton");
}

QString FRadioButtonPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FRadioButtonPlugin::icon() const
{
    return QIcon();
}

QString FRadioButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FRadioButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FRadioButtonPlugin::isContainer() const
{
    return false;
}

QString FRadioButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FRadioButton\" name=\"fRadioButton\">\n</widget>\n");
}

QString FRadioButtonPlugin::includeFile() const
{
    return QLatin1String("fradiobutton.h");
}

