/*
 * MIT License
 *
 * Copyright (c) 2022 KhoaTran Programmer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/********************************************************************
 * PURPOSE                                                          *
 ********************************************************************
 * This is child class of MT_DSA_QMLListObject to define layout for *
 * List object                                                      *
 *******************************************************************/

#include "MT_DSA_QMLListObject.h"

MT_DSA_QMLListObject::MT_DSA_QMLListObject(QQmlEngine& engine, QObject& parent) : MT_DSA_QMLObject(engine, parent)
{

}

MT_DSA_QMLListObject::~MT_DSA_QMLListObject()
{

}

void MT_DSA_QMLListObject::drawObject()
{
    MT_DSA_QMLObject::drawObject();
}

void MT_DSA_QMLListObject::move()
{
    MT_DSA_QMLObject::move();

    if (this->getDrawAnimationStatus() == true)
    {
        // Set node value
        QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateAddress", Q_ARG(QVariant, QString::fromStdString(this->getAddress())));
    }
}

void MT_DSA_QMLListObject::createObject(int x, int y, int w, int h, int animationTime)
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
                            "anchors.verticalCenter: parent.verticalCenter; "
                            "anchors.horizontalCenter: parent.horizontalCenter; "
                            "width: parent.width < parent.height ? parent.width * 0.8 : parent.height * 0.8; "
                            "height: width; "
                            "Text { "
                                "id: id_txt; "
                                "anchors.centerIn: parent; "
                            "}"
                            "Text { "
                                "anchors.bottom: id_name.top; "
                                "anchors.horizontalCenter: parent.horizontalCenter; "
                                "id: id_txt_address; "
                                "color: \"white\";"
                            "}"
                        "}"
                        "function updateText(mytext) { id_txt.text = mytext; } "
                        "function updateAddress(mytext) { id_txt_address.text = mytext; } "
                        "Behavior on x { NumberAnimation { duration: " + QString::number(animationTime) + "}}"
                        "Behavior on y { NumberAnimation { duration: " + QString::number(animationTime) + "}}"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    // Set node value
    QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateText", Q_ARG(QVariant, QString::number(this->getValue())));
    QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateAddress", Q_ARG(QVariant, QString::fromStdString(this->getAddress())));

    _quickitem->setParentItem(myparent);
}
