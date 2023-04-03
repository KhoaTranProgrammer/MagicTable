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
 * This is QML type for Lists                                       *
 *******************************************************************/

#ifndef MT_DSA_QMLLIST_H
#define MT_DSA_QMLLIST_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>
#include <QQuickItemGrabResult>
#include <QDateTime>
#include "MT_DSA_QMLListObject.h"
#include "MT_DSA_List.h"
#include "MT_DSA_ListADT.h"

class MT_DSA_QMLList : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MT_DSA_QMLList(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:
    void featuresChanged();

public slots:
    void addNewDataList(QString value); // 7,5,9,1,31,23,14
    void setObjectAnimationTime(ulong animationtime);
    void createTable(int col, int row);
    void drawData();
    void drawHistoryOneByOne(bool issavefile, QString location);
    void updateDataLocationInTable();
    void updateDataLocationInverseInTable();
    void clearData();
    void removeData(int index);
    void insertData(int index, int value);
    QString getFeatureList();
    void setFeatureList(QString feature);

private:
    QQmlEngine* engine;
    ulong _animationtime;
    MT_DSA_List* _dsa_list = NULL;

    QString LIST_LISTS;
};

#endif // MT_DSA_QMLLIST_H
