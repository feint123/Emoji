#include "fbuttonplugin.h"
#include "ftogglebuttonplugin.h"
#include "fcircleplugin.h"
#include "flabelplugin.h"
#include "fcomboboxplugin.h"
#include "flineeditplugin.h"
#include "ftabwidgetplugin.h"
#include "fcheckboxplugin.h"
#include "fradiobuttonplugin.h"
#include "ftexteditplugin.h"
#include "fimageviewplugin.h"
#include "feintmaterial.h"

FeintMaterial::FeintMaterial(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new FButtonPlugin(this));
    m_widgets.append(new FToggleButtonPlugin(this));
    m_widgets.append(new FCirclePlugin(this));
    m_widgets.append(new FLabelPlugin(this));
    m_widgets.append(new FComboBoxPlugin(this));
    m_widgets.append(new FLineEditPlugin(this));
    m_widgets.append(new FTabWidgetPlugin(this));
    m_widgets.append(new FCheckBoxPlugin(this));
    m_widgets.append(new FRadioButtonPlugin(this));
    m_widgets.append(new FTextEditPlugin(this));
    m_widgets.append(new FImageViewPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> FeintMaterial::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(feintmaterialplugin, FeintMaterial)
#endif // QT_VERSION < 0x050000
