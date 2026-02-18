#ifndef HELLOITEM_H
#define HELLOITEM_H

#include <QQmlEngine>
#include <QQuickCPainterItem>

class HelloItem : public QQuickCPainterItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    HelloItem(QQuickItem *parent = nullptr);
    QQuickCPainterRenderer *createItemRenderer() const override;
private:
    friend class HelloItemRenderer;
    QString m_label;

};

#endif // HELLOITEM_H
