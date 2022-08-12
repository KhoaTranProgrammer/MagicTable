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
 * 1.1.0: Jul-31-2022                                               *
 *        Add list of new data                                      *
 *        Support drawHistoryOneByOne slot                          *
 * 1.2.0: Aug-06-2022                                               *
 *        Supports animation time setting                           *
 * 1.3.0: Aug-09-2022                                               *
 *        Add Bubble sorting                                        *
 * 1.3.1: Aug-12-2022                                               *
 *        Add property Features to select sort type from app        *
 * 1.3.2: Aug-12-2022                                               *
 *        Add to support Selection sort                             *
 *******************************************************************/

#include "MT_DSA_QML.h"

MT_DSA_QML::MT_DSA_QML(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    engine = new QQmlEngine;
    _animationtime = 0;
}

void MT_DSA_QML::paint(QPainter *painter)
{
    _dsa_sorting->createTable((int)this->width(), (int)this->height(), 7, 7);
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
    _dsa_sorting->sortDataWithHistory();
}

void MT_DSA_QML::drawHistoryOneByOne()
{
    _dsa_sorting->drawHistoryOne();
}

void MT_DSA_QML::setObjectAnimationTime(ulong animationtime)
{
    this->_animationtime = animationtime;
}

MT_DSA_QML::Features MT_DSA_QML::features() const
{
    return this->_features;
}

void MT_DSA_QML::setFeatures(const Features& feature)
{
    this->_features = feature;
    if (this->_dsa_sorting != NULL)
        delete this->_dsa_sorting;

    switch(this->_features) {
        case BUBBLE_SORT:
            this->_dsa_sorting = new MT_DSA_SortingBubble();
            break;
        case SELECTION_SORT:
            this->_dsa_sorting = new MT_DSA_SortingSelection();
            break;
    }
}
