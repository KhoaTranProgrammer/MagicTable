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

#include "MT_DSA_QML.h"

MT_DSA_QML::MT_DSA_QML(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    BUBBLE_SORT = "BUBBLE";
    SELECTION_SORT = "SELECTION";
    INSERTION_SORT = "INSERTION";
    MERGE_SORT = "MERGE";
    QUICK_SORT = "QUICK";

    BINARY_SEARCH_TREE = "SEARCH";

    engine = new QQmlEngine;
    _animationtime = 0;
    this->_dsa_sorting = new MT_DSA_SortingBubble();
}

void MT_DSA_QML::paint(QPainter *painter)
{
    if(lines.size() > 0)
    {
        painter->setPen(QPen(Qt::white, 3));
        painter->drawLines(lines);
        lines.clear();
    }
}

void MT_DSA_QML::addNewData(int value)
{
    MT_DSA_QMLObject *obj = new MT_DSA_QMLObject(*engine, *this);
    _dsa_sorting->addData(*obj, value);
}

void MT_DSA_QML::addNewDataList(QString value)
{
    QStringList datalist = value.split(QLatin1Char(','));
    for (int i = 0; i < datalist.count(); i++)
    {
        MT_DSA_QMLObject *obj = new MT_DSA_QMLObject(*engine, *this);
        obj->setAnimationTime(this->_animationtime);
        _dsa_sorting->addDataWithoutSort(*obj, datalist.at(i).toInt());
    }
    update();
}

void MT_DSA_QML::sortDataWithHistory()
{
    _dsa_sorting->sortDataWithHistory();
}

void MT_DSA_QML::sortDataWithMeasurement()
{
    _dsa_sorting->sortDataWithMeasurement();
}

double MT_DSA_QML::getSortMeasurementData()
{
    return _dsa_sorting->elapsedMicroseconds();
}

void MT_DSA_QML::drawData()
{
    if (this->_dsa_sorting != NULL)
        this->_dsa_sorting->drawData();

    if (this->_dsa_hierarchicaltree != NULL)
        this->_dsa_hierarchicaltree->drawData();
}

void MT_DSA_QML::drawHistoryOneByOne()
{
    _dsa_sorting->drawHistoryOne();
}

void MT_DSA_QML::setObjectAnimationTime(ulong animationtime)
{
    this->_animationtime = animationtime;
}

void MT_DSA_QML::setFeatureSorting(QString feature)
{
    if (this->_dsa_sorting != NULL)
        delete this->_dsa_sorting;

    if (feature == BUBBLE_SORT)
        this->_dsa_sorting = new MT_DSA_SortingBubble();
    else if (feature == SELECTION_SORT)
        this->_dsa_sorting = new MT_DSA_SortingSelection();
    else if (feature == INSERTION_SORT)
        this->_dsa_sorting = new MT_DSA_SortingInsertion();
    else if (feature == MERGE_SORT)
        this->_dsa_sorting = new MT_DSA_SortingMerge();
    else if (feature == QUICK_SORT)
        this->_dsa_sorting = new MT_DSA_SortingQuick();
    else
        this->_dsa_sorting = new MT_DSA_SortingBubble();
}

QString MT_DSA_QML::getFeatureSorting()
{
    QString result = "";
    result += BUBBLE_SORT; result += "-";
    result += SELECTION_SORT; result += "-";
    result += INSERTION_SORT; result += "-";
    result += MERGE_SORT; result += "-";
    result += QUICK_SORT;

    return result;
}

void MT_DSA_QML::createTable(int col, int row)
{
    if (this->_dsa_sorting != NULL)
        this->_dsa_sorting->createTable((int)this->width(), (int)this->height(), col, row);

    if (this->_dsa_hierarchicaltree != NULL)
        this->_dsa_hierarchicaltree->createTable((int)this->width(), (int)this->height(), col, row);
}

void MT_DSA_QML::clearData()
{
    if (this->_dsa_sorting != NULL)
    {
        this->_dsa_sorting->clearData();
        delete this->_dsa_sorting;
        this->_dsa_sorting = NULL;
    }

    if (this->_dsa_hierarchicaltree != NULL)
    {
        this->_dsa_hierarchicaltree->clearData();
        delete this->_dsa_hierarchicaltree;
        this->_dsa_hierarchicaltree = NULL;
    }
}

QString MT_DSA_QML::getFeatureHierarchicalTree()
{
    QString result = "";
    result += BINARY_SEARCH_TREE;

    return result;
}

void MT_DSA_QML::setFeatureTree(QString feature)
{
    if (this->_dsa_hierarchicaltree != NULL)
        delete this->_dsa_hierarchicaltree;

    if (feature == BINARY_SEARCH_TREE)
        this->_dsa_hierarchicaltree = new MT_DSA_HierarchicalTree();
}

void MT_DSA_QML::insertNewDataList(QString value)
{
    QStringList datalist = value.split(QLatin1Char(','));
    for (int i = 0; i < datalist.count(); i++)
    {
        MT_DSA_QMLTreeObject *obj = new MT_DSA_QMLTreeObject(*engine, *this);
        this->_dsa_hierarchicaltree->InsertWithEmptyNode(obj, datalist.at(i).toInt());
    }
    this->_dsa_hierarchicaltree->PreorderTraversal();
}

void MT_DSA_QML::drawLine(int startx, int starty, int endx, int endy)
{
    QLineF line(startx, starty, endx, endy);
    lines.append(line);
    update();
}
