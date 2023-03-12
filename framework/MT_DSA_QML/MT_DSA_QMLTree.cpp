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
    AVL_TREE = "AVL";

    engine = new QQmlEngine;
    _elapseTime = 0;
}

void MT_DSA_QMLTree::paint(QPainter *painter)
{

}

void MT_DSA_QMLTree::drawData()
{
    if (this->_dsa_hierarchicaltree != NULL)
    {
        this->_dsa_hierarchicaltree->drawData();
    }

    m_result = this->grabToImage();
    connect(m_result.data(), &QQuickItemGrabResult::ready, this,
    &MT_DSA_QMLTree::grabDone);
}

void MT_DSA_QMLTree::grabDone()
{
    QImage img(m_result.data()->image());
    img.save("D:\\file.png");
}

void MT_DSA_QMLTree::drawHistoryOneByOne()
{
    if (this->_dsa_hierarchicaltree != NULL)
    {
        _dsa_hierarchicaltree->drawHistoryOne();
    }
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
    result += BINARY_SEARCH_TREE; result += "-";
    result += AVL_TREE;

    return result;
}

void MT_DSA_QMLTree::setFeatureTree(QString feature)
{
    if (this->_dsa_hierarchicaltree != NULL)
        delete this->_dsa_hierarchicaltree;

    if (feature == BINARY_SEARCH_TREE)
        this->_dsa_hierarchicaltree = new MT_DSA_BSTADT();
    else if(feature == AVL_TREE)
        this->_dsa_hierarchicaltree = new MT_DSA_AVLADT();
    else
        this->_dsa_hierarchicaltree = new MT_DSA_BSTADT();
}

void MT_DSA_QMLTree::insertNewDataList(QString value)
{
    system_clock::time_point t0 = system_clock::now();
    QStringList datalist = value.split(QLatin1Char(','));
    for (int i = 0; i < datalist.count(); i++)
    {
        MT_DSA_QMLTreeObject *obj = new MT_DSA_QMLTreeObject(*engine, *this);
        obj->setAnimationTime(this->_animationtime);
        this->_dsa_hierarchicaltree->InsertWithEmptyNode(obj, datalist.at(i).toInt());
    }
    this->_dsa_hierarchicaltree->PreorderTraversal();
    system_clock::time_point t1 = system_clock::now();
    this->_elapseTime = double(duration_cast<milliseconds>(t1 - t0).count()) / 1000;
}

void MT_DSA_QMLTree::insertData(int value)
{
    system_clock::time_point t0 = system_clock::now();
    MT_DSA_QMLTreeObject *obj = new MT_DSA_QMLTreeObject(*engine, *this);
    this->_dsa_hierarchicaltree->InsertWithEmptyNode(obj, value);
    this->_dsa_hierarchicaltree->PreorderTraversal();
    system_clock::time_point t1 = system_clock::now();
    this->_elapseTime = double(duration_cast<milliseconds>(t1 - t0).count()) / 1000;
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

int MT_DSA_QMLTree::getColumn()
{
    return this->_dsa_hierarchicaltree->getColumn();
}

int MT_DSA_QMLTree::getHeight()
{
    return this->_dsa_hierarchicaltree->getHeight();
}

void MT_DSA_QMLTree::setObjectAnimationTime(ulong animationtime)
{
    this->_animationtime = animationtime;
}

double_t MT_DSA_QMLTree::getExecutionTime()
{
    return this->_elapseTime;
}
