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
 * 1.0.1: Oct-22-2022                                               *
 *        Add virtual method to free object                         *
 *******************************************************************/

#ifndef MT_DSA_QMLOBJECT_H
#define MT_DSA_QMLOBJECT_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>
#include <QPropertyAnimation>
#include "MT_DSA_Object.h"

class MT_DSA_QMLObject : public MT_DSA_Object
{
public:
    MT_DSA_QMLObject(QQmlEngine& engine, QObject& parent);
    ~MT_DSA_QMLObject();

    void drawObject();
    void move();

private:
    QQmlEngine* _engine;
    QObject* _parent;
    QQmlComponent* _component;
    QQuickItem* _quickitem;
};

#endif // MT_DSA_QMLOBJECT_H
