#include "ftabwidget.h"
#include "ftabwidgetplugin.h"

#include <QtPlugin>

FTabWidgetPlugin::FTabWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FTabWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FTabWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FTabWidgetPlugin::createWidget(QWidget *parent)
{
    return new FTabWidget(parent);
}

QString FTabWidgetPlugin::name() const
{
    return QLatin1String("FTabWidget");
}

QString FTabWidgetPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FTabWidgetPlugin::icon() const
{
    return QIcon();
}

QString FTabWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FTabWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FTabWidgetPlugin::isContainer() const
{
    return false;
}

QString FTabWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FTabWidget\" name=\"fTabWidget\">\n</widget>\n");
}

QString FTabWidgetPlugin::includeFile() const
{
    return QLatin1String("ftabwidget.h");
}

