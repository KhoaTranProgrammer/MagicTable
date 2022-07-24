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
 * This class supports Sorting Algorithm                            *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-24-2022                                               *
 *        Initial version supports: simple sorting                  *
 *******************************************************************/

#include "MT_DSA_Sorting.h"

MT_DSA_Sorting::MT_DSA_Sorting()
{

}

void MT_DSA_Sorting::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

void MT_DSA_Sorting::addData(MT_DSA_Object& obj, int value)
{
    obj.setValue(value);
    this->_listSortObjects.push_back(&obj);
    this->_mttable.addObject(obj);
    this->sortData();
}

void MT_DSA_Sorting::sortData()
{
    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        for(int j = i + 1; j < this->_listSortObjects.size(); j++)
        {
            if(this->_listSortObjects.at(i)->getValue() > this->_listSortObjects.at(j)->getValue())
            {
                MT_DSA_Object* temp = this->_listSortObjects.at(i);
                this->_listSortObjects.at(i) = this->_listSortObjects.at(j);
                this->_listSortObjects.at(j) = temp;
            }
        }
    }

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getRow());
    }

    this->_mttable.drawObjects();
}
