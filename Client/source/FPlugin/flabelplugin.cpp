#include "flabel.h"
#include "flabelplugin.h"

#include <QtPlugin>

FLabelPlugin::FLabelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FLabelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FLabelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FLabelPlugin::createWidget(QWidget *parent)
{
    return new FLabel(parent);
}

QString FLabelPlugin::name() const
{
    return QLatin1String("FLabel");
}

QString FLabelPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FLabelPlugin::icon() const
{
    return QIcon();
}

QString FLabelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FLabelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FLabelPlugin::isContainer() const
{
    return false;
}

QString FLabelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FLabel\" name=\"fLabel\">\n</widget>\n");
}

QString FLabelPlugin::includeFile() const
{
    return QLatin1String("flabel.h");
}

