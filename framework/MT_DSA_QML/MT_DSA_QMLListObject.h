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

#ifndef MT_DSA_QMLLISTOBJECT_H
#define MT_DSA_QMLLISTOBJECT_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>
#include <QPropertyAnimation>
#include "MT_DSA_QMLObject.h"
#include "MT_DSA_QMLArrowObject.h"

class MT_DSA_QMLListObject : public MT_DSA_QMLObject
{
public:
    MT_DSA_QMLListObject(QQmlEngine& engine, QObject& parent);
    ~MT_DSA_QMLListObject();

    void drawObject();
    void move();
    void createObject(int x, int y, int w, int h, int animationTime);
    void createArrow(int x0, int y0, int x1, int y1);

private:
    QQmlComponent* _componentArrow = NULL;
    QQuickItem* _quickitemArrow = NULL;
    int _len;
};

#endif // MT_DSA_QMLLISTOBJECT_H
