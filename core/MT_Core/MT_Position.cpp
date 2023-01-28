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

#include "MT_Position.h"

MT_Position::MT_Position(mt_uint x, mt_uint y, mt_uint w, mt_uint h, mt_uint col, mt_uint row) : MT_Atom()
{
    this->_x = x;
    this->_y = y;
    this->_row = row;
    this->_column = col;
    this->_width = w;
    this->_height = h;
}

mt_uint MT_Position::getColumn()
{
    return this->_column;
}

mt_uint MT_Position::getRow()
{
    return this->_row;
}

mt_uint MT_Position::getX()
{
    return this->_x;
}

mt_uint MT_Position::getY()
{
    return this->_y;
}

mt_uint MT_Position::getW()
{
    return this->_width;
}

mt_uint MT_Position::getH()
{
    return this->_height;
}
