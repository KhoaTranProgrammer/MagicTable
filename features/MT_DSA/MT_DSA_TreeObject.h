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
 * This class stores Node data from Hierarchical Tree               *
 *******************************************************************/

#ifndef MT_DSA_TREEOBJECT_H
#define MT_DSA_TREEOBJECT_H

#include "MT_Object.h"

class MT_DSA_TreeObject : public MT_Object
{
private:
    int _value;

public:
    MT_DSA_TreeObject();
    ~MT_DSA_TreeObject();

    void drawObject();
    void move();

    void setValue(int value);
    int getValue();

    MT_Position* getParentPosition();
    MT_Position* getParentNextPosition();

    // Properties use for Hierarchical Tree
    MT_DSA_TreeObject *_left = NULL;
    MT_DSA_TreeObject *_right = NULL;
    MT_DSA_TreeObject *_parent = NULL;
    int _row;
    int _col;
};

#endif // MT_DSA_TREEOBJECT_H
