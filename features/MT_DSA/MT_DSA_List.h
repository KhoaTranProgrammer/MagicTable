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

#ifndef MT_DSA_LIST_H
#define MT_DSA_LIST_H

#include "MT_Table.h"
#include "MT_DSA_Object.h"

class MT_DSA_List
{
private:
    MT_Table _mttable;
    mt_int _count;
    mt_int *_items;
    vector<MT_DSA_Object*> _listObjects;

public:
    MT_DSA_List();

    mt_void createTable(int w, int h, int col, int row);
    mt_void drawData();
    mt_bool drawHistoryOne();
    mt_void updateDataLocationInTable();
    mt_void updateDataLocationInverseInTable();
    mt_void clearData();

    mt_void Insert(MT_DSA_Object &obj, int index, int val);
    mt_int Get(int index);
    mt_int Search(int val);
    mt_void Remove(int index);
    mt_int Count();
};

#endif // MT_DSA_LIST_H
