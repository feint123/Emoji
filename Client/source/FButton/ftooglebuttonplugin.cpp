#include "ftooglebutton.h"
#include "ftooglebuttonplugin.h"

#include <QtPlugin>

FToogleButtonPlugin::FToogleButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FToogleButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FToogleButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FToogleButtonPlugin::createWidget(QWidget *parent)
{
    return new FToogleButton(parent);
}

QString FToogleButtonPlugin::name() const
{
    return QLatin1String("FToogleButton");
}

QString FToogleButtonPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FToogleButtonPlugin::icon() const
{
    return QIcon();
}

QString FToogleButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FToogleButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FToogleButtonPlugin::isContainer() const
{
    return false;
}

QString FToogleButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FToogleButton\" name=\"fToogleButton\">\n</widget>\n");
}

QString FToogleButtonPlugin::includeFile() const
{
    return QLatin1String("ftooglebutton.h");
}

