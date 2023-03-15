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

#include "MT_DSA_QMLLineObject.h"

MT_DSA_QMLLineObject::MT_DSA_QMLLineObject(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    this->startX = 0;
    this->startY = 0;
    this->stopX = 0;
    this->stopY = 0;
}

void MT_DSA_QMLLineObject::paint(QPainter *painter)
{
    QVector<QLineF> lines;
    QLineF line(startX, startY, stopX, stopY);
    lines.append(line);
    painter->setPen(QPen(Qt::blue, 3));
    painter->drawLines(lines);
    lines.clear();
}

void MT_DSA_QMLLineObject::setStartX(int value)
{
    this->startX = value;
}

void MT_DSA_QMLLineObject::setStartY(int value)
{
    this->startY = value;
}

void MT_DSA_QMLLineObject::setStopX(int value)
{
    this->stopX = value;
}

void MT_DSA_QMLLineObject::setStopY(int value)
{
    this->stopY = value;
}
