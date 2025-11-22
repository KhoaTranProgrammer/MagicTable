#ifndef MT_CHESS_QMLPOSITIONOBJECT_H
#define MT_CHESS_QMLPOSITIONOBJECT_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>
#include <QPropertyAnimation>
#include "MT_Chess_Object.h"
#include <iostream>
using namespace std;

class MT_Chess_QMLPositionObject : public MT_Chess_Object
{
public:
    MT_Chess_QMLPositionObject(QQmlEngine& engine, QObject& parent);
    ~MT_Chess_QMLPositionObject();

    void drawObject();
    void move();
    void createObject(int x, int y, int w, int h, int animationTime);
    void createObject2(int x, int y, int w, int h);
    void clearDrawing();
    void drawSpecific();

protected:
    QQmlEngine* _engine;
    QObject* _parent;
    QQmlComponent* _component = NULL;
    QQuickItem* _quickitem = NULL;
};

#endif // MT_CHESS_QMLPOSITIONOBJECT_H
