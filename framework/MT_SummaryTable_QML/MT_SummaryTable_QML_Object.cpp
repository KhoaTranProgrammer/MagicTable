#include "MT_SummaryTable_QML_Object.h"

MT_SummaryTable_QML_Object::MT_SummaryTable_QML_Object(QQmlEngine& engine, QObject& parent, QString name,
                                                       float point, QString imagelink, int roundnum)
    : MT_Object()
{
    this->_engine = &engine;
    this->_parent = &parent;
    this->_name = name;
    this->_point = point;
    this->_image = imagelink;
    this->_roundNum = roundnum;
}

MT_SummaryTable_QML_Object::~MT_SummaryTable_QML_Object()
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;
}

void MT_SummaryTable_QML_Object::drawObject()
{
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime());
}

void MT_SummaryTable_QML_Object::move()
{
    _quickitem->setProperty("x", this->getNextPosition()->getX());
    _quickitem->setProperty("y", this->getNextPosition()->getY());
}

void MT_SummaryTable_QML_Object::clearDrawing()
{

}

void MT_SummaryTable_QML_Object::drawSpecific()
{

}

void MT_SummaryTable_QML_Object::createObject(int x, int y, int w, int h, int animationTime)
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;

    QString iconUrl = "\"\"";
    QString data =  "import QtQuick 2.0; "
                    "Item { "
                        "x: " + QString::number(x) + ";"
                        "y: " + QString::number(y) + ";"
                                          "width: " + QString::number(w * ((this->_point * (100 / this->_roundNum)) / 100)) + ";"
                        "height: " + QString::number(h) + ";"
                        "Rectangle { "
                            "id: id_name; "
                            "objectName: \"id_name\";"
                            "color: \"blue\";"
                            "anchors.fill: parent;"
                            "anchors.margins: 2;"
                            "Image { "
                                "id: id_img;"
                                "source: \"" + this->_image + "\";"
                                "anchors.left: parent.left;"
                                "anchors.top: parent.top;"
                                "anchors.bottom: parent.bottom;"
                                "width: height;"
                            "}"
                            "Text {"
                                "id: id_txt;"
                                "anchors.margins: 2;"
                                "anchors.left: id_img.right;"
                                "anchors.verticalCenter: parent.verticalCenter;"
                                "font.pointSize: 12;"
                                "font.family: \"Helvetica\";"
                                "text: \"" + this->_name + "\";"
                                "color: \"white\";"
                            "}"
                        "}"
                        "function updateText(mytext) { id_txt.text = mytext; }"
                        "z: 2;"
                        "Behavior on x { NumberAnimation { duration: 800 }}"
                        "Behavior on y { NumberAnimation { duration: 800 }}"
                        "Behavior on width { NumberAnimation { duration: 800 }}"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    _quickitem->setParentItem(myparent);
}

void MT_SummaryTable_QML_Object::setPoint(float point)
{
    this->_point = point;
    _quickitem->setProperty("width", this->getCurPosition()->getW() * ((this->_point * (100 / this->_roundNum)) / 100));
    // Set node value
    QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateText", Q_ARG(QVariant, this->_name + ": " +QString::number(this->_point)));
}

QString MT_SummaryTable_QML_Object::getPlayerName()
{
    return this->_name;
}

float MT_SummaryTable_QML_Object::getPoint()
{
    return this->_point;
}
