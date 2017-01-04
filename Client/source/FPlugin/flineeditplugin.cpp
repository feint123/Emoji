#include "flineedit.h"
#include "flineeditplugin.h"

#include <QtPlugin>

FLineEditPlugin::FLineEditPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FLineEditPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FLineEditPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FLineEditPlugin::createWidget(QWidget *parent)
{
    return new FLineEdit(parent);
}

QString FLineEditPlugin::name() const
{
    return QLatin1String("FLineEdit");
}

QString FLineEditPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FLineEditPlugin::icon() const
{
    return QIcon();
}

QString FLineEditPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FLineEditPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FLineEditPlugin::isContainer() const
{
    return false;
}

QString FLineEditPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FLineEdit\" name=\"fLineEdit\">\n</widget>\n");
}

QString FLineEditPlugin::includeFile() const
{
    return QLatin1String("flineedit.h");
}

