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
 * This class supports Lists Algorithm                              *
 *******************************************************************/

#include "MT_DSA_List.h"

MT_DSA_List::MT_DSA_List()
{
    this->_count = 0;
    this->_items = NULL;
}

mt_void MT_DSA_List::Insert(MT_DSA_Object &obj, int index, int val)
{

}

mt_void MT_DSA_List::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

mt_void MT_DSA_List::drawData()
{
    this->_mttable.drawObjects();
}

mt_bool MT_DSA_List::drawHistoryOne()
{
    return this->_mttable.drawHistoryOne();
}

mt_void MT_DSA_List::updateDataLocationInTable()
{

}

mt_void MT_DSA_List::updateDataLocationInverseInTable()
{

}

mt_void MT_DSA_List::clearData()
{
    this->_listObjects.clear();
    this->_mttable.clearData();
}

mt_void MT_DSA_List::Remove(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index > this->_count)
        return;

    // Copy the current array
    int * oldArray = this->_items;
    vector<MT_DSA_Object*> _oldListObjects = _listObjects;

    // Decrease the array length
    this->_count--;

    // Initialize a new array
    this->_items = new int[this->_count];
    this->_listObjects.clear();

    this->_mttable.removeObject(_oldListObjects.at(index));

    // Fill the new array
    // and remove the selected index
    for(int i=0, j=0; i < this->_count; ++i, ++j)
    {
        if(index == j)
        {
            ++j;
        }

        this->_items[i] = oldArray[j];
        _oldListObjects.at(j)->setValue(this->_items[i]);
        const int *ptr = &this->_items[i];
        ostringstream oss;
        oss << ptr;
        string address_a = oss.str();
        _oldListObjects.at(j)->setAddress(address_a);
        this->_listObjects.push_back(_oldListObjects.at(j));
    }

    // Remove copied array
    if (oldArray != NULL)
    {
        delete [] oldArray;
        _oldListObjects.clear();
    }
}

mt_int MT_DSA_List::Count()
{
    return this->_count;
}
