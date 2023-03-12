#ifndef MT_DSA_QMLLINEOBJECT_H
#define MT_DSA_QMLLINEOBJECT_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>

class MT_DSA_QMLLineObject : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MT_DSA_QMLLineObject(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // MT_DSA_QMLLINEOBJECT_H
