#ifndef MT_SUMMARYTABLE_QML_OBJECT_H
#define MT_SUMMARYTABLE_QML_OBJECT_H

#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>
#include "MT_Object.h"

class MT_SummaryTable_QML_Object : public MT_Object
{
public:
    MT_SummaryTable_QML_Object(QQmlEngine& engine, QObject& parent, QString name, float point);
    ~MT_SummaryTable_QML_Object();

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

private:
    QString _name;
    float _point;
};

#endif // MT_SUMMARYTABLE_QML_OBJECT_H
