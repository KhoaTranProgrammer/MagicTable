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
 * This class describe/process for Position in Magic Table          *
 *******************************************************************/

#ifndef MT_POSITION_H
#define MT_POSITION_H

#include "MT_Types.h"
#include "MT_Atom.h"

class MT_Position : public MT_Atom
{
private:
    mt_uint _x; // Position in actual area
    mt_uint _y; // Position in actual area
    mt_uint _width; // Width length in actual area
    mt_uint _height; // Height length in actual area
    mt_uint _column; // Position in matrix table
    mt_uint _row; // Position in matrix table

public:
    MT_Position(mt_uint x, mt_uint y, mt_uint w, mt_uint h, mt_uint col, mt_uint row);

    mt_uint getColumn();
    mt_uint getRow();
    mt_uint getX();
    mt_uint getY();
    mt_uint getW();
    mt_uint getH();
};

#endif // MT_POSITION_H
