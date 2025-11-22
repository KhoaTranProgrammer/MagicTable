#ifndef MT_KINGCHESS_QML_H
#define MT_KINGCHESS_QML_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>
#include <QQuickItemGrabResult>
#include <QDateTime>
#include "MT_Chess_QMLObject.h"
#include "MT_Chess.h"

class MT_KingChess_QML : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MT_KingChess_QML(QQuickItem *parent = 0);
    void paint(QPainter *painter);

private:
    QQmlEngine* engine;
};

#endif // MT_KINGCHESS_QML_H
