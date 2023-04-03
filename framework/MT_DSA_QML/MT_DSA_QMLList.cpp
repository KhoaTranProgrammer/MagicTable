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

#include "MT_DSA_QMLList.h"

MT_DSA_QMLList::MT_DSA_QMLList(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    LIST_LISTS = "LIST";
    engine = new QQmlEngine;
}

void MT_DSA_QMLList::paint(QPainter *painter)
{

}

void MT_DSA_QMLList::addNewDataList(QString value)
{
    QStringList datalist = value.split(QLatin1Char(','));
    for (int i = 0; i < datalist.count(); i++)
    {
        MT_DSA_QMLListObject *obj = new MT_DSA_QMLListObject(*engine, *this);
        obj->setAnimationTime(this->_animationtime);
        this->_dsa_list->Insert(*obj, i, datalist.at(i).toInt());
    }
}

void MT_DSA_QMLList::setObjectAnimationTime(ulong animationtime)
{
    this->_animationtime = animationtime;
}

void MT_DSA_QMLList::createTable(int col, int row)
{
    if (this->_dsa_list != NULL)
        this->_dsa_list->createTable((int)this->width(), (int)this->height(), col, row);
}

void MT_DSA_QMLList::drawData()
{
    if (this->_dsa_list != NULL)
        this->_dsa_list->drawData();
}

void MT_DSA_QMLList::drawHistoryOneByOne(bool issavefile, QString location)
{
    if (this->_dsa_list != NULL)
    {
        if (_dsa_list->drawHistoryOne())
        {

        }
        else
        {

        }
    }
}

void MT_DSA_QMLList::setFeatureList(QString feature)
{
    if (this->_dsa_list != NULL)
        delete this->_dsa_list;

    if (feature == LIST_LISTS)
        this->_dsa_list = new MT_DSA_ListADT();
    else
        this->_dsa_list = new MT_DSA_ListADT();
}

QString MT_DSA_QMLList::getFeatureList()
{
    QString result = "";
    result += LIST_LISTS;

    return result;
}

void MT_DSA_QMLList::updateDataLocationInTable()
{
    if (this->_dsa_list != NULL)
        this->_dsa_list->updateDataLocationInTable();
}

void MT_DSA_QMLList::updateDataLocationInverseInTable()
{
    if (this->_dsa_list != NULL)
        this->_dsa_list->updateDataLocationInverseInTable();
}

void MT_DSA_QMLList::clearData()
{
    if (this->_dsa_list != NULL)
    {
        this->_dsa_list->clearData();
        delete this->_dsa_list;
        this->_dsa_list = NULL;
    }
}

void MT_DSA_QMLList::removeData(int index)
{
    if (this->_dsa_list != NULL)
        this->_dsa_list->Remove(index);
}

void MT_DSA_QMLList::insertData(int index, int value)
{
    MT_DSA_QMLListObject *obj = new MT_DSA_QMLListObject(*engine, *this);
    obj->setAnimationTime(this->_animationtime);
    this->_dsa_list->Insert(*obj, index, value);
}
