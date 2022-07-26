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
 * This is class to define QML layout of MT_Object                  *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-26-2022                                               *
 *        Initial version supports QML Rectangle                    *
 *******************************************************************/

#include "MT_DSA_QMLObject.h"

MT_DSA_QMLObject::MT_DSA_QMLObject(QQmlEngine& engine, QObject& parent) : MT_DSA_Object()
{
    this->_engine = &engine;
    this->_parent = &parent;
}

void MT_DSA_QMLObject::drawObject()
{
    QString text = "\"" + QString::number(this->getValue()) + "\"";
    QString iconUrl = "\"\"";
    QString data = "import QtQuick 2.0; "
                    "Item { "
                        "id: temp; "
                        "x: " + QString::number(this->getCurPosition()->getX()) + ";"
                        "y: " + QString::number(this->getCurPosition()->getY()) + ";"
                        "width: " + QString::number(this->getCurPosition()->getW()) + ";"
                        "height: " + QString::number(this->getCurPosition()->getH()) + ";"
                        "Rectangle { "
                            "id: id_name; "
                            "color: \"blue\";"
                            "anchors.fill: parent; "
                            "anchors.margins: 10; "
                            "Text { "
                                "anchors.centerIn: parent; "
                                "text: " + text + ";"
                                "font.pointSize: 13; "
                            "}"
                        "}"
                        "Behavior on x { NumberAnimation { duration: 1000} }"
                        "Behavior on y { NumberAnimation { duration: 1000} }"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);
    _quickitem->setParentItem(myparent);
}

void MT_DSA_QMLObject::move()
{
    _quickitem->setProperty("x", this->getNextPosition()->getX());
    _quickitem->setProperty("y", this->getNextPosition()->getY());
}
