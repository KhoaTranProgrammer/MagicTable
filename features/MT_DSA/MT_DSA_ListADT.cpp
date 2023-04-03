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
 * This class supports Lists ADT Algorithm                          *
 *******************************************************************/

#include "MT_DSA_ListADT.h"

MT_DSA_ListADT::MT_DSA_ListADT() : MT_DSA_List()
{

}

mt_void MT_DSA_ListADT::Insert(MT_DSA_Object &obj, int index, int val)
{
    // Check if the index is out of bound
    if(index < 0 || index > this->_count)
        return;

    // Copy the current array
    mt_int *oldArray = this->_items;
    vector<MT_DSA_Object*> _oldListObjects = _listObjects;

    // Increase the array length
    this->_count++;

    // Initialize a new array
    this->_items = new mt_int[this->_count];
    this->_listObjects.clear();

    // Fill the new array with inserted data
    for(int i=0, j=0; i < this->_count; ++i)
    {
        if(index == i)
        {
            this->_items[i] = val;

            // Init new object
            const int *ptr = &this->_items[i];
            ostringstream oss;
            oss << ptr;
            string address_a = oss.str();
            obj.setValue(val);
            obj.setAddress(address_a);

            this->_mttable.addObject(obj);
            this->_listObjects.push_back(&obj);
        }
        else
        {
            this->_items[i] = oldArray[j];
            _oldListObjects.at(j)->setValue(this->_items[i]);
            const int *ptr = &this->_items[i];
            ostringstream oss;
            oss << ptr;
            string address_a = oss.str();
            _oldListObjects.at(j)->setAddress(address_a);
            this->_listObjects.push_back(_oldListObjects.at(j));
            ++j;
        }
    }

    // Remove copied array
    if (oldArray != NULL)
    {
        delete [] oldArray;
        _oldListObjects.clear();
    }
}

mt_void MT_DSA_ListADT::updateDataLocationInTable()
{
    this->_mttable.clearHistory();
    for(int i = 0; i < this->_listObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getCol());
    }
}

mt_void MT_DSA_ListADT::updateDataLocationInverseInTable()
{
    this->_mttable.clearHistory();
    for(int i = this->_listObjects.size() - 1; i >= 0 ; i--)
    {
        this->_mttable.updateObjectPosition(*this->_listObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getCol());
    }
}

mt_int MT_DSA_ListADT::Get(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index > this->_count)
        return -1;

    return this->_items[index];
}

mt_int MT_DSA_ListADT::Search(int val)
{
    // Looping through the array elements
    // return the array index if value is found
    for(int i=0; i < this->_count; ++i)
    {
        if(this->_items[i] == val)
        {
            return i;
        }
    }

    return -1;
}

mt_void MT_DSA_ListADT::Remove(int index)
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
