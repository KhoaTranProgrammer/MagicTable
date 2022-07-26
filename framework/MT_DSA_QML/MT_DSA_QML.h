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
 * This is QML type for Data Structure and Algorithm                *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-26-2022                                               *
 *        Initial version supports simple sorting                   *
 *******************************************************************/

#ifndef MT_DSA_QML_H
#define MT_DSA_QML_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>
#include "MT_DSA_Sorting.h"
#include "MT_DSA_QMLObject.h"

class MT_DSA_QML : public QQuickPaintedItem, public MT_DSA_Sorting
{
    Q_OBJECT
public:
    MT_DSA_QML(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    QQmlEngine* engine;
    vector<MT_DSA_QMLObject*> _listSortObjects;

public slots:
    void addNewData(int value);
};

#endif // MT_DSA_QML_H
