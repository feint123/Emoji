#include "fcombobox.h"
#include "fcomboboxplugin.h"

#include <QtPlugin>

FComboBoxPlugin::FComboBoxPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FComboBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FComboBoxPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FComboBoxPlugin::createWidget(QWidget *parent)
{
    return new FComboBox(parent);
}

QString FComboBoxPlugin::name() const
{
    return QLatin1String("FComboBox");
}

QString FComboBoxPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FComboBoxPlugin::icon() const
{
    return QIcon();
}

QString FComboBoxPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FComboBoxPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FComboBoxPlugin::isContainer() const
{
    return false;
}

QString FComboBoxPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FComboBox\" name=\"fComboBox\">\n</widget>\n");
}

QString FComboBoxPlugin::includeFile() const
{
    return QLatin1String("fcombobox.h");
}

