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
 * This class supports Merge Sorting Algorithm                      *
 *******************************************************************/

#include "MT_DSA_SortingMerge.h"

MT_DSA_SortingMerge::MT_DSA_SortingMerge()
{

}

mt_void MT_DSA_SortingMerge::mergeWithHistory(mt_int startIndex,
                                              mt_int middleIndex,
                                              mt_int endIndex)
{
    // Numbers of elements that will be sorted
    // from startIndex until endIndex
    int totalElements = endIndex - startIndex + 1;

    // Temporary array to store merged array
    vector<MT_DSA_Object*> tempArray(totalElements);

    // Index of left subarray from startIndex -> middleIndex
    int leftIndex = startIndex;

    // Index of right subarray from middleIndex + 1 -> endIndex
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    // Merge the two subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if(this->_listSortObjects.at(leftIndex)->getValue() <= this->_listSortObjects.at(rightIndex)->getValue())
        {
            // Store the left subarray's element if it's lower than the right one
            tempArray.at(mergedIndex) = this->_listSortObjects.at(leftIndex);

            // Go to next left subarray index
            ++leftIndex;
        }
        else
        {
            // Store the right subarray's element if it's lower than the left one
            tempArray.at(mergedIndex) = this->_listSortObjects.at(rightIndex);

            // Go to next right subarray index
            ++rightIndex;
        }

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in left subarray that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray.at(mergedIndex) = this->_listSortObjects.at(leftIndex);

        // Go to next left subarray index
        ++leftIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in right subarray that is not stored to merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray.at(mergedIndex) = this->_listSortObjects.at(rightIndex);

        // Go to next right subarray index
        ++rightIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // Copy the elements to the original array
    for (int i = 0; i < totalElements; ++i)
    {
        this->_listSortObjects.at(startIndex + i) = tempArray.at(i);
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(startIndex + i), (startIndex + i) % this->_mttable.getCol(), ((startIndex + i) / this->_mttable.getCol()));
    }

    return;
}

mt_void MT_DSA_SortingMerge::mergeSortWithHistory(mt_int startIndex,
                                                  mt_int endIndex)
{
    if(startIndex < endIndex)
    {
        // Find middle index
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort left subarray from startIndex to middleIndex
        mergeSortWithHistory(startIndex, middleIndex);

        // Sort right subarray from middleIndex + 1 to endIndex
        mergeSortWithHistory(middleIndex + 1, endIndex);

        // Merge the left and the right subarray
        mergeWithHistory(startIndex, middleIndex, endIndex);
    }

    return;
}

mt_void MT_DSA_SortingMerge::merge(mt_int startIndex,
                                              mt_int middleIndex,
                                              mt_int endIndex)
{
    // Numbers of elements that will be sorted
    // from startIndex until endIndex
    int totalElements = endIndex - startIndex + 1;

    // Temporary array to store merged array
    vector<MT_DSA_Object*> tempArray(totalElements);

    // Index of left subarray from startIndex -> middleIndex
    int leftIndex = startIndex;

    // Index of right subarray from middleIndex + 1 -> endIndex
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    // Merge the two subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if(this->_listSortObjects.at(leftIndex)->getValue() <= this->_listSortObjects.at(rightIndex)->getValue())
        {
            // Store the left subarray's element if it's lower than the right one
            tempArray.at(mergedIndex) = this->_listSortObjects.at(leftIndex);

            // Go to next left subarray index
            ++leftIndex;
        }
        else
        {
            // Store the right subarray's element if it's lower than the left one
            tempArray.at(mergedIndex) = this->_listSortObjects.at(rightIndex);

            // Go to next right subarray index
            ++rightIndex;
        }

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in left subarray that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray.at(mergedIndex) = this->_listSortObjects.at(leftIndex);

        // Go to next left subarray index
        ++leftIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in right subarray that is not stored to merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray.at(mergedIndex) = this->_listSortObjects.at(rightIndex);

        // Go to next right subarray index
        ++rightIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // Copy the elements to the original array
    for (int i = 0; i < totalElements; ++i)
    {
        this->_listSortObjects.at(startIndex + i) = tempArray.at(i);
    }

    return;
}

mt_void MT_DSA_SortingMerge::mergeSort(mt_int startIndex, mt_int endIndex)
{
    if(startIndex < endIndex)
    {
        // Find middle index
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort left subarray from startIndex to middleIndex
        mergeSort(startIndex, middleIndex);

        // Sort right subarray from middleIndex + 1 to endIndex
        mergeSort(middleIndex + 1, endIndex);

        // Merge the left and the right subarray
        merge(startIndex, middleIndex, endIndex);
    }

    return;
}

mt_void MT_DSA_SortingMerge::sortData()
{
    mergeSort(0, this->_listSortObjects.size() - 1);
}

mt_void MT_DSA_SortingMerge::sortDataWithHistory()
{
    this->_mttable.clearHistory();

    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i),
                                            i % this->_mttable.getCol(),
                                            (i / this->_mttable.getCol()));
    }

    mergeSortWithHistory(0, this->_listSortObjects.size() - 1);
}
