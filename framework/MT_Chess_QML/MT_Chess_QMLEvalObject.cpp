#include "MT_Chess_QMLEvalObject.h"

MT_Chess_QMLEvalObject::MT_Chess_QMLEvalObject(QQmlEngine& engine, QObject& parent)
    : MT_Chess_Object()
{
    this->_engine = &engine;
    this->_parent = &parent;
}

MT_Chess_QMLEvalObject::~MT_Chess_QMLEvalObject()
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;
}

void MT_Chess_QMLEvalObject::drawObject()
{

}

void MT_Chess_QMLEvalObject::move()
{

}

void MT_Chess_QMLEvalObject::createObject(int x, int y, int w, int h, int animationTime, string pattern)
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;

    QString iconUrl = "\"\"";
    QString data = "import QtQuick 2.0; "
                    "Item { "
                        "x: " + QString::number(x + w * 0.5) + ";"
                        "y: " + QString::number(y) + ";"
                        "width: " + QString::number(w * 0.5) + ";"
                        "height: " + QString::number(h * 0.5) + ";"
                        "Rectangle { "
                            "id: id_name; "
                            "objectName: \"id_name\";"
                            "color: \"transparent\";"
                            "anchors.fill: parent;"
                            "Image { "
                                "source: Qt.platform.os === \"android\" ? (\"assets:/icon/" + QString::fromStdString(pattern) + ".png\") : (\"icon/" + QString::fromStdString(pattern) + ".png\");"
                                "anchors.fill: parent;"
                                "anchors.margins: parent.width * 0.1;"
                            "}"
                        "}"
                        "z: 2;"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    _quickitem->setParentItem(myparent);
}

void MT_Chess_QMLEvalObject::clearDrawing()
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

void MT_Chess_QMLEvalObject::drawSpecific()
{

}

void MT_Chess_QMLEvalObject::drawSpecific(string pattern)
{
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime(),
                       pattern);
}
