#include "quicklistitem.h"

#include <pane/markdown/domain/markdownquick.h>

QuickListItem::QuickListItem()
{

}

void QuickListItem::updateItem(QVariant item)
{
    MarkdownQuick quick=qvariant_cast<MarkdownQuick>(item);
}
