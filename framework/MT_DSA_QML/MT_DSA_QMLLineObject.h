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
 * This is QML type to draw line object                             *
 *******************************************************************/

#ifndef MT_DSA_QMLLINEOBJECT_H
#define MT_DSA_QMLLINEOBJECT_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>

class MT_DSA_QMLLineObject : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int startX WRITE setStartX)
    Q_PROPERTY(int startY WRITE setStartY)
    Q_PROPERTY(int stopX WRITE setStopX)
    Q_PROPERTY(int stopY WRITE setStopY)

public:
    MT_DSA_QMLLineObject(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    void setStartX(int value);
    void setStartY(int value);
    void setStopX(int value);
    void setStopY(int value);

private:
    int startX;
    int startY;
    int stopX;
    int stopY;
};

#endif // MT_DSA_QMLLINEOBJECT_H
