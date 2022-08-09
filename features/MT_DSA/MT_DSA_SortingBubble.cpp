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
 * This class supports Bubble Sorting Algorithm                     *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Aug-09-2022                                               *
 *        Initial version                                           *
 *******************************************************************/

#include "MT_DSA_SortingBubble.h"

MT_DSA_SortingBubble::MT_DSA_SortingBubble()
{

}

void MT_DSA_SortingBubble::sortData()
{
    // The flag are used for swapping
    mt_bool isSwapped;

    // The number of elements will be sorted. This value will be decreased when complete sort for one element
    mt_int unsortedElements = this->_listSortObjects.size();
    do
    {
        // This value will be true in case 2 elements need to be swapped
        isSwapped = false;

        // Loop the array's element
        for(mt_int i = 0; i < unsortedElements - 1; ++i)
        {
            if(this->_listSortObjects.at(i)->getValue() > this->_listSortObjects.at(i+1)->getValue())
            {
                MT_DSA_Object* temp = this->_listSortObjects.at(i);
                this->_listSortObjects.at(i) = this->_listSortObjects.at(i+1);
                this->_listSortObjects.at(i+1) = temp;
                this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), (i / this->_mttable.getCol()),
                                                    *this->_listSortObjects.at(i+1), (i+1) % this->_mttable.getCol(), ((i+1) / this->_mttable.getCol()));
                isSwapped = true;
            }
        }

        --unsortedElements;
    }
    // In case the array is not complete sorted, this value is false
    while(isSwapped);

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getRow());
    }

    this->_mttable.drawObjects();
}

mt_void MT_DSA_SortingBubble::sortDataWithHistory()
{
    this->_mttable.clearHistory();

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i),
                                            i % this->_mttable.getCol(),
                                            (i / this->_mttable.getCol()));
    }

    // The flag are used for swapping
    mt_bool isSwapped;

    // The number of elements will be sorted. This value will be decreased when complete sort for one element
    mt_int unsortedElements = this->_listSortObjects.size();
    do
    {
        // This value will be true in case 2 elements need to be swapped
        isSwapped = false;

        // Loop the array's element
        for(mt_int i = 0; i < unsortedElements - 1; ++i)
        {
            if(this->_listSortObjects.at(i)->getValue() > this->_listSortObjects.at(i+1)->getValue())
            {
                MT_DSA_Object* temp = this->_listSortObjects.at(i);
                this->_listSortObjects.at(i) = this->_listSortObjects.at(i+1);
                this->_listSortObjects.at(i+1) = temp;
                this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), (i / this->_mttable.getCol()),
                                                    *this->_listSortObjects.at(i+1), (i+1) % this->_mttable.getCol(), ((i+1) / this->_mttable.getCol()));
                isSwapped = true;
            }
        }

        --unsortedElements;
    }
    // In case the array is not complete sorted, this value is false
    while(isSwapped);
}
