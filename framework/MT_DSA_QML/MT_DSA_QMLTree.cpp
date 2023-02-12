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

#include "MT_DSA_QMLTree.h"

MT_DSA_QMLTree::MT_DSA_QMLTree(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    BINARY_SEARCH_TREE = "SEARCH";

    engine = new QQmlEngine;
}

void MT_DSA_QMLTree::paint(QPainter *painter)
{
    if(lines.size() == 0)
    {
        QRectF r1(0, 0, this->width(), this->height());
        painter->fillRect(r1, QColor("transparent"));
    }
    else
    {
        painter->setPen(QPen(Qt::white, 3));
        painter->drawLines(lines);
        lines.clear();
    }

}

void MT_DSA_QMLTree::drawData()
{
    if (this->_dsa_hierarchicaltree != NULL)
        this->_dsa_hierarchicaltree->drawData();
}

void MT_DSA_QMLTree::createTable(int col, int row)
{
    if (this->_dsa_hierarchicaltree != NULL)
        this->_dsa_hierarchicaltree->createTable((int)this->width(), (int)this->height(), col, row);
}

void MT_DSA_QMLTree::clearData()
{
    if (this->_dsa_hierarchicaltree != NULL)
    {
        this->_dsa_hierarchicaltree->clearData();
        delete this->_dsa_hierarchicaltree;
        this->_dsa_hierarchicaltree = NULL;
    }
}

QString MT_DSA_QMLTree::getFeatureHierarchicalTree()
{
    QString result = "";
    result += BINARY_SEARCH_TREE;

    return result;
}

void MT_DSA_QMLTree::setFeatureTree(QString feature)
{
    if (this->_dsa_hierarchicaltree != NULL)
        delete this->_dsa_hierarchicaltree;

    if (feature == BINARY_SEARCH_TREE)
        this->_dsa_hierarchicaltree = new MT_DSA_HierarchicalTree();
    else
        this->_dsa_hierarchicaltree = new MT_DSA_HierarchicalTree();
}

void MT_DSA_QMLTree::insertNewDataList(QString value)
{
    QStringList datalist = value.split(QLatin1Char(','));
    for (int i = 0; i < datalist.count(); i++)
    {
        MT_DSA_QMLTreeObject *obj = new MT_DSA_QMLTreeObject(*engine, *this);
        this->_dsa_hierarchicaltree->InsertWithEmptyNode(obj, datalist.at(i).toInt());
    }
    this->_dsa_hierarchicaltree->PreorderTraversal();
}

void MT_DSA_QMLTree::insertData(int value)
{
    MT_DSA_QMLTreeObject *obj = new MT_DSA_QMLTreeObject(*engine, *this);
    this->_dsa_hierarchicaltree->InsertWithEmptyNode(obj, value);
    this->_dsa_hierarchicaltree->PreorderTraversal();
}

void MT_DSA_QMLTree::drawLine(int startx, int starty, int endx, int endy)
{
    QLineF line(startx, starty, endx, endy);
    lines.append(line);
    update();
}

void MT_DSA_QMLTree::Remove(int key)
{
    update();
    this->_dsa_hierarchicaltree->Remove(key);
    this->_dsa_hierarchicaltree->PreorderTraversal();
}
