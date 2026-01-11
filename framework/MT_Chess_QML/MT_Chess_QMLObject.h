#ifndef MT_CHESS_QMLOBJECT_H
#define MT_CHESS_QMLOBJECT_H

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

class MT_Chess_QMLObject : public MT_Chess_Object
{
public:
    MT_Chess_QMLObject(QQmlEngine& engine, QObject& parent, string piece, string color, int animationtime);
    ~MT_Chess_QMLObject();

    void drawObject();
    void move();
    void createObject(int x, int y, int w, int h, int animationTime);
    void clearDrawing();
    void drawSpecific();

protected:
    QQmlEngine* _engine;
    QObject* _parent;
    QQmlComponent* _component = NULL;
    QQuickItem* _quickitem = NULL;
    int _animationTime = 500;
};

#endif // MT_CHESS_QMLOBJECT_H
