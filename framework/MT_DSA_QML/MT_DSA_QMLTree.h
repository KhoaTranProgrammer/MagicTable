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
 * This is QML type for Hierarchical Tree                           *
 *******************************************************************/

#ifndef MT_DSA_QMLTREE_H
#define MT_DSA_QMLTREE_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>
#include <QQuickItemGrabResult>
#include "MT_DSA_QMLTreeObject.h"
#include "MT_DSA_HierarchicalTree.h"
#include "MT_DSA_BSTADT.h"
#include "MT_DSA_AVLADT.h"
#include <chrono>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

class MT_DSA_QMLTree : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MT_DSA_QMLTree(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:
    void featuresChanged();

public slots:
    void createTable(int col, int row);
    void drawData();
    void drawHistoryOneByOne();
    void clearData();

    QString getFeatureHierarchicalTree();
    void setFeatureTree(QString feature);
    void insertNewDataList(QString value); // 23,12,31,3,15,7,29,88,53
    void insertData(int value); // 50
    void drawLine(int startx, int starty, int endx, int endy);
    void Remove(int key);
    int getColumn();
    int getHeight();
    void setObjectAnimationTime(ulong animationtime);
    double getExecutionTime();

private:
    void grabDone();
    QSharedPointer<QQuickItemGrabResult> m_result;

    MT_DSA_HierarchicalTree* _dsa_hierarchicaltree = NULL;
    QQmlEngine* engine;
    QVector<QLineF> lines;
    QString BINARY_SEARCH_TREE;
    QString AVL_TREE;
    ulong _animationtime;
    double _elapseTime;
};

#endif // MT_DSA_QMLTREE_H
