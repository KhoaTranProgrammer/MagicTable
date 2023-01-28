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

#ifndef MT_DSA_QML_H
#define MT_DSA_QML_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>
#include "MT_DSA_Sorting.h"
#include "MT_DSA_SortingBubble.h"
#include "MT_DSA_SortingSelection.h"
#include "MT_DSA_SortingInsertion.h"
#include "MT_DSA_SortingMerge.h"
#include "MT_DSA_SortingQuick.h"
#include "MT_DSA_QMLObject.h"

class MT_DSA_QML : public QQuickPaintedItem
{
    Q_OBJECT
public:

    MT_DSA_QML(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:
    void featuresChanged();

public slots:
    void addNewData(int value);
    void addNewDataList(QString value); // 7,5,9,1,31,23,14
    void drawHistoryOneByOne();
    void setObjectAnimationTime(ulong animationtime);
    void createTable(int col, int row);
    QString getFeatureSorting();
    void setFeatureSorting(QString feature);
    void sortDataWithHistory();
    void sortDataWithMeasurement();
    double getSortMeasurementData();
    void drawData();
    void clearData();

private:
    MT_DSA_Sorting* _dsa_sorting = NULL;
    QQmlEngine* engine;
    vector<MT_DSA_QMLObject*> _listSortObjects;
    ulong _animationtime;

    QString BUBBLE_SORT;
    QString SELECTION_SORT;
    QString INSERTION_SORT;
    QString MERGE_SORT;
    QString QUICK_SORT;
};

#endif // MT_DSA_QML_H
