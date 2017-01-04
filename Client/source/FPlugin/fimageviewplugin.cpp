#include "fimageview.h"
#include "fimageviewplugin.h"

#include <QtPlugin>

FImageViewPlugin::FImageViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FImageViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool FImageViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FImageViewPlugin::createWidget(QWidget *parent)
{
    return new FImageView(parent);
}

QString FImageViewPlugin::name() const
{
    return QLatin1String("FImageView");
}

QString FImageViewPlugin::group() const
{
    return QLatin1String("Material");
}

QIcon FImageViewPlugin::icon() const
{
    return QIcon();
}

QString FImageViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FImageViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FImageViewPlugin::isContainer() const
{
    return false;
}

QString FImageViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FImageView\" name=\"fImageView\">\n</widget>\n");
}

QString FImageViewPlugin::includeFile() const
{
    return QLatin1String("fimageview.h");
}

