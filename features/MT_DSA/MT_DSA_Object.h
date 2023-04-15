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
 * This class supports data processing for Data Structure/Algorithm *
 *******************************************************************/

#ifndef MT_DSA_OBJECT_H
#define MT_DSA_OBJECT_H

#include "MT_Object.h"
#include <sstream>
#include <iostream>

class MT_DSA_Object : public MT_Object
{
private:
    int _value;
    string _address;
    MT_DSA_Object *_next;

public:
    MT_DSA_Object();
    ~MT_DSA_Object();

    void drawObject();
    void move();

    void setValue(int value);
    int getValue();

    void setAddress(string value);
    string getAddress();

    MT_DSA_Object *getNextNode();
    mt_void setNextNode(MT_DSA_Object *node);

    MT_Position* getNextNodePosition();
};

#endif // MT_DSA_OBJECT_H
