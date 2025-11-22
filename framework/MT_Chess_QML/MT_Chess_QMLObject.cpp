#include "MT_Chess_QMLObject.h"

MT_Chess_QMLObject::MT_Chess_QMLObject(QQmlEngine& engine, QObject& parent, string piece, string color)
    : MT_Chess_Object(piece, color)
{
    this->_engine = &engine;
    this->_parent = &parent;
}

MT_Chess_QMLObject::~MT_Chess_QMLObject()
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;
}

void MT_Chess_QMLObject::drawObject()
{
    // cout << "MT_Chess_QMLObject::drawObject" << endl;
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime());
}

void MT_Chess_QMLObject::move()
{
    cout << "MT_Chess_QMLObject::move" << endl;
    // this->createObject(this->getNextPosition()->getX(), this->getNextPosition()->getY(),
    //                    this->getNextPosition()->getW(), this->getNextPosition()->getH(),
    //                    this->getAnimationTime());
    _quickitem->setProperty("x", this->getNextPosition()->getX());
    _quickitem->setProperty("y", this->getNextPosition()->getY());
}

void MT_Chess_QMLObject::clearDrawing()
{

}

void MT_Chess_QMLObject::drawSpecific()
{
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime());
}

void MT_Chess_QMLObject::createObject(int x, int y, int w, int h, int animationTime)
{
    // cout << "MT_Chess_QMLObject::createObject"
    //      << " x: " << x
    //      << " y: " << y
    //      << " w: " << w
    //      << " h: " << h
    //      << endl;

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
                            "color: \"transparent\";"
                            "anchors.fill: parent;"
                            "Image { "
                               "source: Qt.platform.os === \"android\" ? (\"assets:/icon/" + QString::fromStdString(this->getColor()) + "_" + QString::fromStdString(this->getPiece()) + ".png\") : (\"icon/" + QString::fromStdString(this->getColor()) + "_" + QString::fromStdString(this->getPiece()) + ".png\");"
                               "anchors.fill: parent;"
                               "anchors.margins: parent.width * 0.1;"
                            "}"
                        "}"
                        "z: 2;"
                        "Behavior on x { NumberAnimation { duration: 500 }}"
                        "Behavior on y { NumberAnimation { duration: 500 }}"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    _quickitem->setParentItem(myparent);
}
