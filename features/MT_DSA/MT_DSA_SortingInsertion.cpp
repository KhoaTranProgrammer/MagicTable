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
 * This class supports Insertion Sorting Algorithm                  *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Aug-14-2022                                               *
 *        Initial version                                           *
 * 1.0.1: Aug-21-2022                                               *
 *        Separate draw data from sorting                           *
 *******************************************************************/

#include "MT_DSA_SortingInsertion.h"

MT_DSA_SortingInsertion::MT_DSA_SortingInsertion()
{

}

void MT_DSA_SortingInsertion::sortData()
{
    // Loop to all array's element
    for(int i = 0; i < this->_listSortObjects.size(); ++i)
    {
        // Set the current element as reference value
        MT_DSA_Object* refValue = this->_listSortObjects.at(i);

        // Variable to shift the element to right position
        int j;

        // Iterate through the sorted element to insert the reference value in right position
        for(j = i - 1; j >= 0; --j)
        {
            // If the value of the current index is greater than the reference value then
            // move the current value to right side otherwise, put the reference value
            // in the current index
            if(this->_listSortObjects.at(j)->getValue() > refValue->getValue())
            {
                this->_listSortObjects.at(j+1) = this->_listSortObjects.at(j);
            }
            else
                break;
        }

        // Put the reference value in the current index (the right position)
        this->_listSortObjects.at(j+1) = refValue;
    }
}

mt_void MT_DSA_SortingInsertion::sortDataWithHistory()
{
    this->_mttable.clearHistory();

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i),
                                            i % this->_mttable.getCol(),
                                            (i / this->_mttable.getCol()));
    }

    // Loop to all array's element
    for(int i = 0; i < this->_listSortObjects.size(); ++i)
    {
        // Set the current element as reference value
        MT_DSA_Object* refValue = this->_listSortObjects.at(i);

        // Variable to shift the element to right position
        int j;

        // Iterate through the sorted element to insert the reference value in right position
        for(j = i - 1; j >= 0; --j)
        {
            // If the value of the current index is greater than the reference value then
            // move the current value to right side otherwise, put the reference value
            // in the current index
            if(this->_listSortObjects.at(j)->getValue() > refValue->getValue())
            {
                this->_listSortObjects.at(j+1) = this->_listSortObjects.at(j);
                this->_mttable.updateObjectPosition(*this->_listSortObjects.at(j+1), (j+1) % this->_mttable.getCol(), ((j+1) / this->_mttable.getCol()));
            }
            else
                break;
        }

        // Put the reference value in the current index (the right position)
        this->_listSortObjects.at(j+1) = refValue;
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(j+1), (j+1) % this->_mttable.getCol(), ((j+1) / this->_mttable.getCol()));
    }
}
