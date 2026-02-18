#ifndef HELLOITEMRENDERER_H
#define HELLOITEMRENDERER_H

#include <QQuickCPainterRenderer>
#include <QImage>

class HelloItemRenderer : public QQuickCPainterRenderer
{
public:
    HelloItemRenderer();

    // QQuickCPainterRenderer interface
protected:
    void paint(QCPainter *painter) override;
    void synchronize(QQuickCPainterItem *item) override;

private:
    QString m_label;
    QImage m_logoImage;
};

#endif // HELLOITEMRENDERER_H
