#include "helloitem.h"
#include "helloitemrenderer.h"

HelloItem::HelloItem(QQuickItem *parent)
    :  QQuickCPainterItem(parent)
{
    m_label = QString("Canvas Painter");
}

QQuickCPainterRenderer *HelloItem::createItemRenderer() const
{
    // Create the renderer for this item
    return new HelloItemRenderer();
}
