#include "ftextedit.h"
#include "ftexteditplugin.h"

#include <QtPlugin>

FTextEditPlugin::FTextEditPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FTextEditPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FTextEditPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FTextEditPlugin::createWidget(QWidget *parent)
{
    return new FTextEdit(parent);
}

QString FTextEditPlugin::name() const
{
    return QLatin1String("FTextEdit");
}

QString FTextEditPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FTextEditPlugin::icon() const
{
    return QIcon();
}

QString FTextEditPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FTextEditPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FTextEditPlugin::isContainer() const
{
    return false;
}

QString FTextEditPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FTextEdit\" name=\"fTextEdit\">\n</widget>\n");
}

QString FTextEditPlugin::includeFile() const
{
    return QLatin1String("ftextedit.h");
}

