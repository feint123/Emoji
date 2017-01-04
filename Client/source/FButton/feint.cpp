#include "fbuttonplugin.h"
#include "ftooglebuttonplugin.h"
#include "feint.h"

Feint::Feint(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new FButtonPlugin(this));
    m_widgets.append(new FToogleButtonPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> Feint::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(feintplugin, Feint)
#endif // QT_VERSION < 0x050000
