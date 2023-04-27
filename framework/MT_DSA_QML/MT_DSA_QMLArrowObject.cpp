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
 * This is QML type to draw arrow object                            *
 *******************************************************************/

#include "MT_DSA_QMLArrowObject.h"
#include <cmath>

MT_DSA_QMLArrowObject::MT_DSA_QMLArrowObject(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    this->startX = 0;
    this->startY = 0;
    this->stopX = 0;
    this->stopY = 0;
    this->lengh = 0;
}

void MT_DSA_QMLArrowObject::paint(QPainter *painter)
{
    QVector<QLineF> lines;

    if (startY == stopY) // Current and Next are in the same line
    {
        if (stopX > startX) // Next's in the right of Current
        {
            stopX = stopX - this->lengh;
        }
        else // Next's in the left of Current
        {
            stopX = stopX + this->lengh;
        }
    }
    else // Current and Next are not in the same line
    {
        if (stopX == startX) // Current and Next are in the same column
        {
            if (stopY > startY) // Next's in the bottom of Current
            {
                stopY = stopY - this->lengh;
            }
            else // Next's in the top of Current
            {
                stopY = stopY + this->lengh;
            }
        }
        else // Current and Next are not in the same column
        {
            if (stopY > startY) // Next's in the bottom of Current
            {
                stopY = stopY - this->lengh;
            }
            else // Next's in the top of Current
            {
                stopY = stopY + this->lengh;
            }

            if (stopX > startX) // Next's in the right of Current
            {
                stopX = stopX - this->lengh;
            }
            else // Next's in the left of Current
            {
                stopX = stopX + this->lengh;
            }
        }
    }

    QLineF line(startX, startY, stopX, stopY);

    const int dx = stopX - startX;
    const int dy = stopY - startY;
    const double headlen = 10; // length of head in pixels
    const double angle = atan2(dy, dx);

    QLineF line1(stopX, stopY, stopX - headlen * cos(angle - M_PI / 6), stopY - headlen * sin(angle - M_PI / 6));
    QLineF line2(stopX, stopY, stopX - headlen * cos(angle + M_PI / 6), stopY - headlen * sin(angle + M_PI / 6));

    lines.append(line);
    lines.append(line1);
    lines.append(line2);
    painter->setPen(QPen(Qt::blue, 3));
    painter->drawLines(lines);
    lines.clear();
}

void MT_DSA_QMLArrowObject::setStartX(int value)
{
    this->startX = value;
}

void MT_DSA_QMLArrowObject::setStartY(int value)
{
    this->startY = value;
}

void MT_DSA_QMLArrowObject::setStopX(int value)
{
    this->stopX = value;
}

void MT_DSA_QMLArrowObject::setStopY(int value)
{
    this->stopY = value;
}

void MT_DSA_QMLArrowObject::setLengh(int value)
{
    this->lengh = value;
}
