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

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-21-2022                                               *
 *        Initial version supports: Add/update/draw Object          *
 *******************************************************************/

#ifndef MT_TABLE_H
#define MT_TABLE_H

#include <vector>
#include "MT_Atom.h"
#include "MT_Object.h"
#include "MT_Position.h"

class MT_Table : public MT_Atom
{
private:
    vector<MT_Object*> _objectlist;
    vector<MT_Position*> _matrixposition;
    mt_uint _actual_width; // Actual width in pixel unit
    mt_uint _actual_height; // Actual height in pixel unit
    mt_uint _position_width; // Position width in pixel unit
    mt_uint _position_height; // Position height in pixel unit
    mt_uint _row; // Number of rows in table
    mt_uint _column; // Numner of columns in table

public:
    MT_Table();

    mt_void createTable(mt_uint w, mt_uint h, mt_uint col, mt_uint row);
    mt_void addObject(mt_uint col, mt_uint row);
    mt_void addObject(MT_Object& obj, mt_uint col, mt_uint row);
    mt_void addObject(MT_Object& obj);
    MT_Position* getPositionAt(mt_uint col, mt_uint row);
    mt_bool updateObjectPosition(MT_Object& obj, mt_uint col, mt_uint row);
    mt_uint getRow();
    mt_uint getCol();

    mt_void drawObjects();

    bool checkValidPosition(mt_uint col, mt_uint row);
};

#endif // MT_TABLE_H
