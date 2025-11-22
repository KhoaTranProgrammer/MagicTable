#include "MT_Chess_QMLPositionObject.h"

MT_Chess_QMLPositionObject::MT_Chess_QMLPositionObject(QQmlEngine& engine, QObject& parent)
    : MT_Chess_Object()
{
    this->_engine = &engine;
    this->_parent = &parent;
}

MT_Chess_QMLPositionObject::~MT_Chess_QMLPositionObject()
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;
}

void MT_Chess_QMLPositionObject::clearDrawing()
{
    if (this->_quickitem != NULL) {
        delete this->_quickitem;
        this->_quickitem = NULL;
    }
    if (this->_component != NULL) {
        delete this->_component;
        this->_component = NULL;
    }
}

void MT_Chess_QMLPositionObject::drawSpecific()
{
    this->createObject2(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH());
}

void MT_Chess_QMLPositionObject::drawObject()
{
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime());
}

void MT_Chess_QMLPositionObject::move()
{
    this->createObject(this->getNextPosition()->getX(), this->getNextPosition()->getY(),
                       this->getNextPosition()->getW(), this->getNextPosition()->getH(),
                       this->getAnimationTime());
}

void MT_Chess_QMLPositionObject::createObject(int x, int y, int w, int h, int animationTime)
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;

    QString iconUrl = "\"\"";
    QString data = "import QtQuick 2.0; "
                   "Item { "
                        "x: " + QString::number(x) + ";"
                        "y: " + QString::number(y) + ";"
                        "width: " + QString::number(w) + ";"
                        "height: " + QString::number(h) + ";"
                        "Rectangle { "
                            "id: id_name; "
                            "objectName: \"id_name\";"
                            "color: \"yellow\";"
                            "anchors.fill: parent;"
                            "anchors.margins: parent.width * 0.05;"
                            "opacity: 0.3;"
                            "radius: width * 0.5"
                        "}"
                    "}";

    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    _quickitem->setParentItem(myparent);
}

void MT_Chess_QMLPositionObject::createObject2(int x, int y, int w, int h)
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;

    QString iconUrl = "\"\"";
    QString data = "import QtQuick 2.0; "
                   "Item { "
                        "x: " + QString::number(x) + ";"
                        "y: " + QString::number(y) + ";"
                        "width: " + QString::number(w) + ";"
                        "height: " + QString::number(h) + ";"
                        "Rectangle { "
                            "id: id_name; "
                            "objectName: \"id_name\";"
                            "color: \"red\";"
                            "anchors.fill: parent;"
                            "anchors.margins: parent.width * 0.05;"
                            "opacity: 0.3;"
                            "radius: width * 0.5"
                        "}"
                    "}";

    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    _quickitem->setParentItem(myparent);
}
