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
 * This class supports Selection Sorting Algorithm                  *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Aug-12-2022                                               *
 *        Initial version                                           *
 * 1.0.1: Aug-21-2022                                               *
 *        Separate draw data from sorting                           *
 *******************************************************************/

#include "MT_DSA_SortingSelection.h"

MT_DSA_SortingSelection::MT_DSA_SortingSelection()
{

}

void MT_DSA_SortingSelection::sortData()
{
    // Index of the minimum value in each iteration
    int minIndex;

    // Iterate until the N-1 elements
    for(int i = 0; i < this->_listSortObjects.size() - 1; ++i)
    {
        // Set the first unsorted element as the minimum value
        minIndex = i;

        // Iterate through the unsorted elements only
        for(int j = i + 1; j < this->_listSortObjects.size(); ++j)
        {
            // set the new minimum value if the saved minimum value is higher
            // than the current index value
            if (this->_listSortObjects.at(j)->getValue() < this->_listSortObjects.at(minIndex)->getValue())
                minIndex = j;
        }

        // Swap the the first unsorted element with the minimum value
        MT_DSA_Object* temp = this->_listSortObjects.at(i);
        this->_listSortObjects.at(i) = this->_listSortObjects.at(minIndex);
        this->_listSortObjects.at(minIndex) = temp;
    }
}

mt_void MT_DSA_SortingSelection::sortDataWithHistory()
{
    this->_mttable.clearHistory();

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i),
                                            i % this->_mttable.getCol(),
                                            (i / this->_mttable.getCol()));
    }

    // Index of the minimum value in each iteration
    int minIndex;

    // Iterate until the N-1 elements
    for(int i = 0; i < this->_listSortObjects.size() - 1; ++i)
    {
        // Set the first unsorted element as the minimum value
        minIndex = i;

        // Iterate through the unsorted elements only
        for(int j = i + 1; j < this->_listSortObjects.size(); ++j)
        {
            // set the new minimum value if the saved minimum value is higher
            // than the current index value
            if (this->_listSortObjects.at(j)->getValue() < this->_listSortObjects.at(minIndex)->getValue())
                minIndex = j;
        }

        // Swap the the first unsorted element with the minimum value
        MT_DSA_Object* temp = this->_listSortObjects.at(i);
        this->_listSortObjects.at(i) = this->_listSortObjects.at(minIndex);
        this->_listSortObjects.at(minIndex) = temp;
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), (i / this->_mttable.getCol()),
                                            *this->_listSortObjects.at(minIndex), (minIndex) % this->_mttable.getCol(), ((minIndex) / this->_mttable.getCol()));
    }
}
