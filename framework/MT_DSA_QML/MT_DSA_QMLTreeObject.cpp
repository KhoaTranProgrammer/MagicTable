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
 * This is class to define QML layout of MT_DSA_TreeObject          *
 *******************************************************************/

#include "MT_DSA_QMLTreeObject.h"

MT_DSA_QMLTreeObject::MT_DSA_QMLTreeObject(QQmlEngine& engine, QObject& parent)
{
    this->_engine = &engine;
    this->_parent = &parent;
}

MT_DSA_QMLTreeObject::~MT_DSA_QMLTreeObject()
{
    if (this->_quickitem != NULL)
        delete this->_quickitem;
    if (this->_component != NULL)
        delete this->_component;
    if (this->_quickitemLine != NULL)
        delete this->_quickitemLine;
    if (this->_componentLine != NULL)
        delete this->_componentLine;
}

void MT_DSA_QMLTreeObject::drawObject()
{
    this->createObject(this->getCurPosition()->getX(), this->getCurPosition()->getY(),
                       this->getCurPosition()->getW(), this->getCurPosition()->getH(),
                       this->getAnimationTime());

    MT_Position* parentposition = this->getParentPosition();
    if (parentposition != NULL)
    {
        this->createLine(
            this->getCurPosition()->getX() + (this->getCurPosition()->getW() / 2),
            this->getCurPosition()->getY() + (this->getCurPosition()->getH() / 2),
            parentposition->getX() + (parentposition->getW() / 2),
            parentposition->getY() + (parentposition->getH() / 2));
    }
}

void MT_DSA_QMLTreeObject::move()
{
    if (this->getDrawAnimationStatus() == true)
    {
        // Set node value
        QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateText", Q_ARG(QVariant, QString::number(this->getValue())));

        _quickitem->setProperty("x", this->getNextPosition()->getX());
        _quickitem->setProperty("y", this->getNextPosition()->getY());
        _quickitem->setProperty("width", this->getNextPosition()->getW());
        _quickitem->setProperty("height", this->getNextPosition()->getH());

        MT_Position* parentposition = this->getParentPosition();
        if (parentposition != NULL)
        {
            this->createLine(
                this->getNextPosition()->getX() + (this->getNextPosition()->getW() / 2),
                this->getNextPosition()->getY() + (this->getNextPosition()->getH() / 2),
                parentposition->getX() + (parentposition->getW() / 2),
                parentposition->getY() + (parentposition->getH() / 2));
        }
    }
    else
    {
        this->createObject(this->getNextPosition()->getX(), this->getNextPosition()->getY(),
                           this->getNextPosition()->getW(), this->getNextPosition()->getH(),
                           this->getAnimationTime());

        MT_Position* parentposition = this->getParentNextPosition();
        if (parentposition != NULL)
        {
            this->createLine(
                this->getNextPosition()->getX() + (this->getNextPosition()->getW() / 2),
                this->getNextPosition()->getY() + (this->getNextPosition()->getH() / 2),
                parentposition->getX() + (parentposition->getW() / 2),
                parentposition->getY() + (parentposition->getH() / 2));
        }
    }
}

void MT_DSA_QMLTreeObject::createObject(int x, int y, int w, int h, int animationTime)
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
                            "width: 20; "
                            "height: width; "
                            "Text { "
                                "id: id_txt; "
                                "anchors.centerIn: parent; "
                                "font.pointSize: 9; "
                            "}"
                        "}"
                        "function updateText(mytext) { id_txt.text = mytext; } "
                        "Behavior on x { NumberAnimation { duration: " + QString::number(animationTime) + "}}"
                        "Behavior on y { NumberAnimation { duration: " + QString::number(animationTime) + "}}"
                    "}";
    _component = new QQmlComponent(this->_engine);
    _component->setData(data.toUtf8(), QUrl());
    _quickitem = qobject_cast<QQuickItem*>(_component->create());
    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    // Set node value
    QMetaObject::invokeMethod(qobject_cast<QObject*>(_quickitem), "updateText", Q_ARG(QVariant, QString::number(this->getValue())));

    _quickitem->setParentItem(myparent);
}

void MT_DSA_QMLTreeObject::createLine(int x0, int y0, int x1, int y1)
{
    if (this->_quickitemLine != NULL)
        delete this->_quickitemLine;
    if (this->_componentLine != NULL)
        delete this->_componentLine;

    QQuickItem* myparent = qobject_cast<QQuickItem*>(this->_parent);

    QString data_line = "";
    data_line = "import QtQuick 2.0; "
                        "Canvas { "
                            "id: mycanvas; "
                            "anchors.fill: parent; "
                            "z: -1; "
                            "onPaint: { "
                                "var ctx = getContext('2d'); "
                                "ctx.beginPath(); "
                                "ctx.strokeStyle = \"white\"; "
                                "ctx.lineWidth = 3; "
                                "ctx.moveTo(" + QString::number(x0) + "," +
                                                QString::number(y0) + "); "
                                "ctx.lineTo(" + QString::number(x1) + "," +
                                                QString::number(y1) + "); "
                                "ctx.stroke(); "
                                "ctx.closePath(); "
                            "}"
                        "}";
    _componentLine = new QQmlComponent(this->_engine);
    _componentLine->setData(data_line.toUtf8(), QUrl());
    _quickitemLine = qobject_cast<QQuickItem*>(_componentLine->create());

    // Set parent for new items
    _quickitemLine->setParentItem(myparent);
}
