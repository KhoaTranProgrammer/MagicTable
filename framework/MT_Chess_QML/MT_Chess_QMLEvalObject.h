#ifndef MT_CHESS_QMLEVALOBJECT_H
#define MT_CHESS_QMLEVALOBJECT_H

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

class MT_Chess_QMLEvalObject : public MT_Chess_Object
{
public:
    MT_Chess_QMLEvalObject(QQmlEngine& engine, QObject& parent);
    ~MT_Chess_QMLEvalObject();

    void drawObject();
    void move();
    void createObject(int x, int y, int w, int h, int animationTime, string pattern);
    void clearDrawing();
    void drawSpecific();
    void drawSpecific(string pattern);

protected:
    QQmlEngine* _engine;
    QObject* _parent;
    QQmlComponent* _component = NULL;
    QQuickItem* _quickitem = NULL;
};

#endif // MT_CHESS_QMLEVALOBJECT_H
