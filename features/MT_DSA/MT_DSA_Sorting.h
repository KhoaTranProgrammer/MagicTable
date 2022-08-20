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
 * 1.1.0: Jul-31-2022                                               *
 *        Supports sort/draw history all and one by one             *
 * 1.2.0: Aug-09-2022                                               *
 *        Add Bubble sorting                                        *
 * 1.3.0: Aug-20-2022                                               *
 *        Support Time Measurement                                  *
 *******************************************************************/

#ifndef MT_DSA_SORTING_H
#define MT_DSA_SORTING_H

#include "MT_Table.h"
#include "MT_Object.h"
#include "MT_DSA_Object.h"
#include <bits/stdc++.h>

class MT_DSA_Sorting
{
private:
    clock_t _startexecutiontime;
    clock_t _stopexecutiontime;

protected:
    MT_Table _mttable;
    vector<MT_DSA_Object*> _listSortObjects;

public:
    MT_DSA_Sorting();

    mt_void createTable(int w, int h, int col, int row);
    mt_void addData(MT_DSA_Object& obj, int value);
    mt_void addDataWithoutSort(MT_DSA_Object& obj, int value);
    virtual mt_void sortData();
    virtual mt_void sortDataWithHistory();
    mt_void drawHistoryAll();
    mt_void drawHistoryOne();
    mt_void startMeasure();
    mt_void stopMeasure();
    mt_double elapsedMicroseconds();
};

#endif // MT_DSA_SORTING_H
