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
 * This class describe/process for Table in Magic Table             *
 *******************************************************************/

#ifndef MT_TABLE_H
#define MT_TABLE_H

#include <vector>
#include "MT_Atom.h"
#include "MT_Object.h"
#include "MT_Position.h"
#include "MT_RefObject.h"

class MT_Table : public MT_Atom
{
private:
    vector<MT_Object*> _objectlist;
    vector<vector<MT_Position*>> _matrixposition;
    mt_uint _actual_width; // Actual width in pixel unit
    mt_uint _actual_height; // Actual height in pixel unit
    mt_uint _position_width; // Position width in pixel unit
    mt_uint _position_height; // Position height in pixel unit
    mt_uint _row; // Number of rows in table
    mt_uint _column; // Numner of columns in table
    vector<vector<MT_RefObject*>> _history; // History moving of objects in table
    mt_uint _index_history; // Current index in History

public:
    MT_Table();

    mt_void createTable(mt_uint w, mt_uint h, mt_uint col, mt_uint row);
    mt_void updateTable(mt_uint newcol, mt_uint newrow);
    mt_void addObject(mt_uint col, mt_uint row);
    mt_void addObject(MT_Object& obj, mt_uint col, mt_uint row);
    mt_void addObject(MT_Object& obj);
    MT_Position* getPositionAt(mt_uint col, mt_uint row);
    mt_bool updateObjectPosition(MT_Object& obj, mt_uint col, mt_uint row);
    mt_bool updateObjectPosition(MT_Object& obj1, mt_uint col1, mt_uint row1,
                                 MT_Object& obj2, mt_uint col2, mt_uint row2);
    mt_uint getRow();
    mt_uint getCol();

    mt_void drawObjects();

    bool checkValidPosition(mt_uint col, mt_uint row);
    mt_void clearHistory();
    mt_void drawHistoryAll();
    mt_bool drawHistoryOne();
    mt_void clearData();
    mt_void removeObject(MT_Object* obj);
};

#endif // MT_TABLE_H
