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
 * This class supports Quick Sorting Algorithm                      *
 *******************************************************************/

#include "MT_DSA_SortingQuick.h"

MT_DSA_SortingQuick::MT_DSA_SortingQuick()
{

}

mt_int MT_DSA_SortingQuick::partitionWithHistory(mt_int startIndex, mt_int endIndex)
{
    // Set the first item as pivot
    MT_DSA_Object* pivot = this->_listSortObjects.at(startIndex);

    // Left sublist and right sublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (this->_listSortObjects.at(i)->getValue() < pivot->getValue())
        {
            // the current item is on the left sublist
            // prepare a seat by shifting middle index
            ++middleIndex;

            // the arr[middleIndex] is
            // the member of right sublist,
            // swap it to the current item which is
            // member of left list
            MT_DSA_Object* temp = this->_listSortObjects.at(i);
            this->_listSortObjects.at(i) = this->_listSortObjects.at(middleIndex);
            this->_listSortObjects.at(middleIndex) = temp;
            this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), (i / this->_mttable.getCol()),
                                                *this->_listSortObjects.at(middleIndex), (middleIndex) % this->_mttable.getCol(), ((middleIndex) / this->_mttable.getCol()));
        }
    }

    // By now, the arr[middleIndex] item is
    // member of left sublist.
    // We can swap it with the pivot
    // so the pivot will be in the correct position
    // which is between left sublist and right sublist
    MT_DSA_Object* temp = this->_listSortObjects.at(startIndex);
    this->_listSortObjects.at(startIndex) = this->_listSortObjects.at(middleIndex);
    this->_listSortObjects.at(middleIndex) = temp;
    this->_mttable.updateObjectPosition(*this->_listSortObjects.at(startIndex), startIndex % this->_mttable.getCol(), (startIndex / this->_mttable.getCol()),
                                        *this->_listSortObjects.at(middleIndex), (middleIndex) % this->_mttable.getCol(), ((middleIndex) / this->_mttable.getCol()));

    // return the index of pivot
    // to be used by next quick sort
    return middleIndex;
}

mt_void MT_DSA_SortingQuick::quickSortWithHistory(mt_int startIndex, mt_int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if (startIndex < endIndex)
    {
        // Retrieve pivot position from Partition() function
        // This pivotIndex is the index of element that is already
        // in correct position
        int pivotIndex = partitionWithHistory(startIndex, endIndex);

        // Sort left sublist
        // arr[startIndex ... pivotIndex - 1]
        quickSortWithHistory(startIndex, pivotIndex - 1);

        // Sort right sublist
        // arr[pivotIndex + 1 ... endIndex]
        quickSortWithHistory(pivotIndex + 1, endIndex);
    }
}

mt_int MT_DSA_SortingQuick::partition(mt_int startIndex, mt_int endIndex)
{
    // Set the first item as pivot
    MT_DSA_Object* pivot = this->_listSortObjects.at(startIndex);

    // Left sublist and right sublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (this->_listSortObjects.at(i)->getValue() < pivot->getValue())
        {
            // the current item is on the left sublist
            // prepare a seat by shifting middle index
            ++middleIndex;

            // the arr[middleIndex] is
            // the member of right sublist,
            // swap it to the current item which is
            // member of left list
            MT_DSA_Object* temp = this->_listSortObjects.at(i);
            this->_listSortObjects.at(i) = this->_listSortObjects.at(middleIndex);
            this->_listSortObjects.at(middleIndex) = temp;
        }
    }

    // By now, the arr[middleIndex] item is
    // member of left sublist.
    // We can swap it with the pivot
    // so the pivot will be in the correct position
    // which is between left sublist and right sublist
    MT_DSA_Object* temp = this->_listSortObjects.at(startIndex);
    this->_listSortObjects.at(startIndex) = this->_listSortObjects.at(middleIndex);
    this->_listSortObjects.at(middleIndex) = temp;

    // return the index of pivot
    // to be used by next quick sort
    return middleIndex;
}

mt_void MT_DSA_SortingQuick::quickSort(mt_int startIndex, mt_int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if (startIndex < endIndex)
    {
        // Retrieve pivot position from Partition() function
        // This pivotIndex is the index of element that is already
        // in correct position
        int pivotIndex = partition(startIndex, endIndex);

        // Sort left sublist
        // arr[startIndex ... pivotIndex - 1]
        quickSort(startIndex, pivotIndex - 1);

        // Sort right sublist
        // arr[pivotIndex + 1 ... endIndex]
        quickSort(pivotIndex + 1, endIndex);
    }
}

mt_void MT_DSA_SortingQuick::sortData()
{
    quickSort(0, this->_listSortObjects.size() - 1);
}

mt_void MT_DSA_SortingQuick::sortDataWithHistory()
{
    this->_mttable.clearHistory();

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i),
                                            i % this->_mttable.getCol(),
                                            (i / this->_mttable.getCol()));
    }

    quickSortWithHistory(0, this->_listSortObjects.size() - 1);
}
