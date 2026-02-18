#include "helloitemrenderer.h"
#include "helloitem.h"
#include <QCRadialGradient>
#include <QCImage>
#include <QCImagePattern>

HelloItemRenderer::HelloItemRenderer()
    : QQuickCPainterRenderer()
    , m_logoImage(":/qt/qml/canvaspainter_helloworld/qt-translucent.png")
{
    // Convert m_logoImage QImage to a black and white image.
    QImage::Format format;
    // format = QImage::Format_Grayscale8;
    format = QImage::Format_Mono;
    m_logoImage = m_logoImage.convertToFormat(format, Qt::ThresholdDither);
}


void HelloItemRenderer::synchronize(QQuickCPainterItem *item)
{
    // Synchronize here data between the item and the renderer.
    HelloItem *helloItem = static_cast<HelloItem*>(item);
    m_label = helloItem->m_label;
}

void HelloItemRenderer::paint(QCPainter *p)
{
    float size = std::min(width(), height());
    QPointF center(width() * 0.5, height() * 0.5);

    // Paint the background circle
    QCRadialGradient gradient1(center, size * 0.6);
    gradient1.setStartColor(0x909090);
    gradient1.setEndColor(0x202020);
    p->beginPath();
    p->circle(center, size * 0.46);
    p->setFillStyle(gradient1);
    p->fill();
    p->setStrokeStyle(0x202020);
    p->setLineWidth(size * 0.02);
    p->stroke();

    // Paint texts
    p->setTextAlign(QCPainter::TextAlign::Center);
    p->setTextBaseline(QCPainter::TextBaseline::Middle);
    QFont font1("Titillium Web");
    font1.setWeight(QFont::Weight::Bold);
    font1.setItalic(true);
    font1.setPixelSize(size * 0.08);
    p->setFont(font1);
    p->setFillStyle(0x2CDE85);
    p->fillText("HELLO", center.x(), center.y() - size * 0.28);
    QFont font2("Titillium Web");
    font2.setWeight(QFont::Weight::Thin);
    font2.setPixelSize(size * 0.12);
    p->setFont(font2);
    p->fillText(m_label, center.x(), center.y() - size * 0.16);

    // Paint the heart
    QCImage logo = p->addImage(m_logoImage, QCPainter::ImageFlag::Repeat |
                                                QCPainter::ImageFlag::GenerateMipmaps);
    float pSize = size * 0.05;
    QCImagePattern pattern(logo, center.x(), center.y(), pSize, pSize);
    p->setFillStyle(pattern);
    p->setStrokeStyle(0x2CDE85);
    p->beginPath();
    float hs = size * 2;
    QPointF hc(width() * 0.5, height() * 0.25);
    p->moveTo(hc.x(), hc.y() + hs * 0.3);
    p->bezierCurveTo(hc.x() - hs * 0.25, hc.y() + hs * 0.1,
                     hc.x(), hc.y() + hs * 0.05,
                     hc.x(), hc.y() + hs * 0.18);
    p->bezierCurveTo(hc.x(), hc.y() + hs * 0.05,
                     hc.x() + hs * 0.25, hc.y() + hs * 0.1,
                     hc.x(), hc.y() + hs * 0.3);
    p->fill();
    p->stroke();
}
