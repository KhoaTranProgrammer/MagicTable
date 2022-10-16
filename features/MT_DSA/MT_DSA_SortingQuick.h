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

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Aug-14-2022                                               *
 *        Initial version                                           *
 * 1.0.1: Aug-21-2022                                               *
 *        Separate draw data from sorting                           *
 *******************************************************************/

#ifndef MT_DSA_SORTINGQUICK_H
#define MT_DSA_SORTINGQUICK_H

#include "MT_DSA_Sorting.h"

class MT_DSA_SortingQuick : public MT_DSA_Sorting
{
private:
    mt_int partitionWithHistory(mt_int startIndex, mt_int endIndex);
    mt_void quickSortWithHistory(mt_int startIndex, mt_int endIndex);
    mt_int partition(mt_int startIndex, mt_int endIndex);
    mt_void quickSort(mt_int startIndex, mt_int endIndex);

public:
    MT_DSA_SortingQuick();
    mt_void sortData();
    mt_void sortDataWithHistory();
};

#endif // MT_DSA_SORTINGQUICK_H